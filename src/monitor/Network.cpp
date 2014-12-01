//
// Network.cpp for * in /home/petit_p//projets/Zappy/local
// 
// Made by pierre petit
// Login   <petit_p@epitech.net>
// 
// Started on  Fri May 10 11:42:34 2013 pierre petit
// Last update Sun Jul 14 17:19:56 2013 pierre petit
//

#include "Network.hh"
#include "ParseCom.hh"
#include "Buffer.hh"
#include "Signal.hh"

Network::Network()
{
  this->_port = 4242;
  this->_ip = "127.0.0.1";
  this->_protocol = "TCP";
  this->_talk = new Talk;
  this->_cmd = "";
}

Network::Network(Parser *k)
{
  this->_port = k->getPort();
  this->_ip = this->solveHostName(k->getDomain());
  this->_protocol = "TCP";
  this->_talk = new Talk;
}

Network::~Network()
{}

const std::string &	Network::solveHostName(const std::string & domain)
{
  struct hostent *host;
  struct in_addr **adr;
  char		*ip_tmp = new char [128];

  host = gethostbyname(domain.c_str());
  if (host == NULL)
    throw Exception("Host not found");
  for (adr = (struct in_addr **)host->h_addr_list ; *adr ; adr++)
    ip_tmp = inet_ntoa(**adr);
  if (ip_tmp == NULL)
    throw Exception("Unable to retrieve IP address");
  this->_ip = ip_tmp;
  return (this->_ip);
}

void	Network::doSocket()
{
  this->_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (this->_fd == -1)
    throw Exception("Socket error.");
}

void	Network::doProtoByName(std::string &protocol)
{
  if ((this->_pe = getprotobyname(protocol.c_str())) == NULL)
    throw Exception("getprotobyname error.");
}

void	Network::doConnection()
{
  this->_sIn.sin_family = AF_INET;
  this->_sIn.sin_port = htons(this->_port);
  this->_sIn.sin_addr.s_addr = inet_addr(this->_ip.c_str());
  if (connect(this->_fd, (struct sockaddr *)&this->_sIn, sizeof(this->_sIn)) == -1)
    throw Exception("Connection to serveur failed.");
  else
    std::cout << "Welcome, your are connected on the " << this->_ip << " server." << std::endl;
  this->sendGraphic();
}

void	Network::tryToConnect()
{
  this->doProtoByName(this->_protocol);
  this->doSocket();
  this->doConnection();
}

void	Network::sendGraphic()
{
  this->_talk->sendMsg(this->_fd, "GRAPHIC");
}

void	Network::play()
{
  CreateMap		*m = new CreateMap(this->_fd);
  ParsCom		Parse(m, this, this->_talk);
  fd_set                fd;
  std::string		msgBuffer;
  Buffer		B1(10);
  Signal		s(this->_fd);
  unsigned int	       	pos = 0;
  unsigned int		i = 0;

  this->_selectTime.tv_sec = 1200;
  this->_selectTime.tv_usec = 0;
  while (1)
    {
      FD_ZERO(&fd);
      FD_SET(this->_fd, &fd);
      FD_SET(0, &fd);
      if (m->getIsInit() == true && i == 0)
	{
	  std::cout << "For a better follow of the camera, press Enter." << std::endl;
	  i = 1;
	}
      if ((select(this->_fd + 1, &fd, NULL, NULL, &this->_selectTime)) != -1)
        {
	  s.detectSignal();
	  if (FD_ISSET(this->_fd, &fd))
	    {
	      this->_talk->recvMsg(this->_fd);
	      if (this->_talk->getSizeRead() > 0)
		{
		  this->_cmd += this->_talk->getMsgRead();
		  if (this->_talk->getMsgRead().at(0) == '\n')
		    {
		      if (B1.getCapacity() <= pos)
			pos = B1.getCapacity() - 1;
		      B1.pushElements(this->_cmd);
		      msgBuffer = B1.getCurrentElement(pos);
		      std::cout << msgBuffer << std::endl;
		      Parse.Pars(msgBuffer);
		      msgBuffer.clear();
		      this->_cmd.clear();
		    }
		  this->_talk->getMsgRead().clear();
		}
	    }
	  if (m->getIsInit() == true)
	    m->get3dMap()->drawAllMembers();
	}
    }
}

std::string const & Network::getCmd() const
{
  return (this->_cmd);
}
