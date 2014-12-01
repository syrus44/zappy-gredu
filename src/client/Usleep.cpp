//
// usleep.cpp for  in /home/dugast_a//SystemUnix/zappy/lv/zappy-gredu/trunk/Zappy
// 
// Made by antoine dugast
// Login   <dugast_a@epitech.net>
// 
// Started on  Thu Jul  4 11:00:35 2013 antoine dugast
// Last update Fri Jul 12 00:12:02 2013 louis cailleux
//

#include	"Usleep.hh"

Usleep::Usleep()
{
  this->usec = 1;
}

Usleep::Usleep(useconds_t const &usec)
{
  this->usec = usec;
}

Usleep::~Usleep()
{}

void		Usleep::launchSleep() const
{
  usleep(this->usec);
}
