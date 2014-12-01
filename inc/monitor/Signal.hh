//
// Signal.hh for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Fri Jul 12 14:01:06 2013 louis cailleux
// Last update Sun Jul 14 14:27:39 2013 louis cailleux
//

#include <csignal>

#ifndef SIGNAL_HH_
# define SIGNAL_HH_

class	Signal
{
  int	_fd;
public:
  Signal(int);
  void	detectSignal() const;
  ~Signal();
};

void	intHandler(int);

#endif
