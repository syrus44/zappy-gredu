//
// Signal.cpp for Zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Fri Jul 12 14:05:36 2013 louis cailleux
// Last update Sun Jul 14 18:47:16 2013 pierre petit
//

#include "Signal.hh"
#include "Exception.hh"

static int sock;

Signal::Signal(int fd)
{
  this->_fd = fd;
  sock = fd;
}

Signal::~Signal()
{}

void	Signal::detectSignal() const
{
  if (signal(SIGINT, intHandler) == SIG_IGN ||
      signal(SIGQUIT, intHandler) == SIG_IGN)
    {
      close(this->_fd);
      throw Exception("Disconnected from server");
    }
}

void	intHandler(int sig)
{
  signal(sig, SIG_IGN);
}
