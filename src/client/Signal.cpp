//
// Signal.cpp for Zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Fri Jul 12 14:05:36 2013 louis cailleux
// Last update Fri Jul 12 14:08:12 2013 louis cailleux
//

#include "Signal.hh"
#include "Exception.hh"

Signal::Signal()
{}

Signal::~Signal()
{}

void	Signal::detectSignal() const
{
  if (signal(SIGINT, intHandler) == SIG_IGN ||
      signal(SIGQUIT, intHandler) == SIG_IGN)
    throw Exception ("Disconnected from server");
}

void	intHandler(int sig)
{
  signal(sig, SIG_IGN);
}

