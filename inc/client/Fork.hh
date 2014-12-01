//
// Fork.hh for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Wed Jul 10 11:39:54 2013 louis cailleux
// Last update Wed Jul 10 11:54:14 2013 louis cailleux
//

#ifndef	FORK_HH_
# define FORK_HH_

#include	<unistd.h>

class	Fork
{
  pid_t		pid;
public:
  Fork();
  pid_t	getPid() const;
  void	cFork();
  ~Fork();
};

#endif
