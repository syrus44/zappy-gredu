//
// Network.hh for  in /home/petit_p//projets/Zappy/local
// 
// Made by pierre petit
// Login   <petit_p@epitech.net>
// 
// Started on  Fri May 10 11:36:42 2013 pierre petit
// Last update Thu Jul  4 18:24:43 2013 louis cailleux
//

#ifndef	_NETWORK_HH
#define	_NETWORK_HH

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "CreateMap.hh"
#include "Parser.hh"
#include "Talk.hh"

class	Network
{
private:
  int			_port;
  int			_fd;
  std::string		_ip;
  std::string		_cmd;
  struct timeval        _selectTime;
  std::string		_protocol;
  struct protoent      *_pe;
  struct hostent       *_host;
  struct sockaddr_in	_sIn;
  Talk		       *_talk;

  // CONSTRUCTEUR ET DESTRUCTEURS
public:
  Network();
  Network(Parser *);
  ~Network();

  // FONCTIONS MEMBRES
public:
  const std::string &	solveHostName(const std::string &);
  void			sendGraphic();
  void			doSocket();
  void			doProtoByName(std::string &);
  void			doConnection();
  void			tryToConnect();
  void			receiveFromServer();
  void			sendToServer();
  void			play();
  unsigned int		secureCmd(int);
  std::string const &	getCmd() const;
};

#endif /*_NETWORK_HH*/
