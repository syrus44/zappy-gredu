//
// Talk.cpp for  in /home/petit_p//projets/Zappy/zappy-gredu/trunk/sparw
// 
// Made by pierre petit
// Login   <petit_p@epitech.net>
// 
// Started on  Thu Jun 13 10:48:03 2013 pierre petit
// Last update Thu Jul 11 23:56:42 2013 louis cailleux
//

#include "Talk.hh"
#include "Exception.hh"

Talk::Talk()
{}

Talk::~Talk()
{}

void		Talk::sendMsg(int const &fd, std::string const &msg)
{
  int		st = 0;

  std::cout << msg << std::endl;
  st = send(fd, msg.c_str(), msg.size(), 0);
  if (st < 1 || msg.size() < 1)
    throw Exception("Message not sent ! Connexion lost");
}

void		Talk::recvMsg(int const &fd)
{
  int	i = 0;

  this->_sizeRead = recv(fd, this->_msgTmp, 1, 0);
  this->_msgRead = this->_msgTmp;
  if (this->_msgRead.size() < 1)
    throw Exception("Disconnected by the server");
  while (this->_msgTmp[i])
    {
      this->_msgTmp[i] = '\0';
      i++;
    }
}

int		Talk::getSizeRead() const
{
  return (this->_sizeRead);
}

std::string	Talk::getMsgRead() const
{
  return (this->_msgRead);
}
