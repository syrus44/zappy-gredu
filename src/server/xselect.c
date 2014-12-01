/*
** xselect.c for xselect in /home/bettin_j//ZappySockets
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 13:57:25 2013 jordan bettin
** Last update Sun Jul 14 19:43:28 2013 pierre petit
*/

#include	"server.h"

int		xselect(int nfds, fd_set *readfds, fd_set *writefds,
			fd_set *exceptfds, struct timeval *timeout)
{
  int		st;

  st = select(nfds, readfds, writefds, exceptfds, timeout);
  if (st <= 0)
    {
      errno = EBADF | EINVAL;
      fprintf(stderr, "The time is elapsed ! The game is finished\n");
      return (-1);
    }
  return (st);
}
