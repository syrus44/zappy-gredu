//
// WaitPid.cpp for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Wed Jul 10 12:02:01 2013 louis cailleux
// Last update Fri Jul 12 00:14:14 2013 louis cailleux
//

#include "Exception.hh"
#include "WaitPid.hh"

WaitPid::WaitPid()
{
  this->pid = 0;
}

WaitPid::~WaitPid()
{}

void	WaitPid::setPid(pid_t const &pid)
{
  this->pid = pid;
}

void	WaitPid::wait() const
{
  int	i;
  if (waitpid(pid, &i, 0) != 0)
    throw Exception("Disconnected by the server");
}
