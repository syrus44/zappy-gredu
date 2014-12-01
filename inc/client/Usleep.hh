//
// usleep.hh for  in /home/dugast_a//SystemUnix/zappy/lv/zappy-gredu/trunk/Zappy
// 
// Made by antoine dugast
// Login   <dugast_a@epitech.net>
// 
// Started on  Thu Jul  4 11:02:27 2013 antoine dugast
// Last update Fri Jul 12 00:12:13 2013 louis cailleux
//

#ifndef		USLEEP_HH
#define		USLEEP_HH

#include	<unistd.h>

class		Usleep
{
private:
  useconds_t	usec;
public:
  Usleep();
  Usleep(useconds_t const &);
  ~Usleep();
  void		launchSleep() const;
};

#endif		/*USLEEP_HH*/
