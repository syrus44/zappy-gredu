//
// Network.hh for  in /home/petit_p//projets/Zappy/local
// 
// Made by pierre petit
// Login   <petit_p@epitech.net>
// 
// Started on  Fri May 10 11:36:42 2013 pierre petit
// Last update Fri Jul 12 00:11:33 2013 louis cailleux
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

#include "Parser.hh"
#include "Talk.hh"

class	Network
{
private:
  int			_port;
  int			_fd;
  std::string		_ip;
  std::string		_team;
  struct timeval        _selectTime;
  std::string		_protocol;
  struct protoent      *_pe;
  struct sockaddr_in	_sIn;
  std::string		_cmd;	
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
  void			doProtoByName(std::string const &);
  void			doConnection();
  void			tryToConnect();
  void			receiveFromServer();
  void			sendToServer();
  void			play();
  std::string const &	getCmd() const;
};

#endif /*_NETWORK_HH*/
