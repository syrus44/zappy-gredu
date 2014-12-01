//
// Talk.hh for  in /home/petit_p//projets/Zappy/zappy-gredu/trunk/sparw
// 
// Made by pierre petit
// Login   <petit_p@epitech.net>
// 
// Started on  Thu Jun 13 10:46:09 2013 pierre petit
// Last update Thu Jul 11 23:56:28 2013 louis cailleux
//

#ifndef	_TALK_HH_
#define	_TALK_HH_

#include <sys/socket.h>
#include <sys/types.h>
#include <iostream>

class	Talk
{
protected:
  std::string	_msgRead;
  int		_sizeRead;
  char		_msgTmp[1];

public:
  Talk();
  ~Talk();

public:
  void		sendMsg(int const &, std::string const &);
  void		recvMsg(int const &);

public:
  int		getSizeRead() const;
  std::string	getMsgRead() const;
};

#endif /*_TALK_HH_*/
