//
// WaitPid.hh for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Wed Jul 10 11:55:38 2013 louis cailleux
// Last update Fri Jul 12 00:13:57 2013 louis cailleux
//

#ifndef WAITPID_HH_
# define WAITPID_HH_

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

class	WaitPid
{
  pid_t	pid;
public:
  WaitPid();
  ~WaitPid();
  void	wait() const;
  void	setPid(pid_t const &);
};

#endif
