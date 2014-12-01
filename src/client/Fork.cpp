//
// Fork.cpp for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Wed Jul 10 11:45:39 2013 louis cailleux
// Last update Wed Jul 10 11:53:43 2013 louis cailleux
//

#include "Fork.hh"
#include "Exception.hh"

Fork::Fork()
{
  this->pid = -1;
}

Fork::~Fork()
{}

void	Fork::cFork()
{
  if ((this->pid = fork()) < 0)
    throw Exception("Fork failed");
}

pid_t	Fork::getPid() const
{
  return (this->pid);
}

