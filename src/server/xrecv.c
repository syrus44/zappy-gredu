/*
** xrecv.c for  in /home/petit_p//projets/Zappy/zappy-gredu/trunk/sparw
** 
** Made by pierre petit
** Login   <petit_p@epitech.net>
** 
** Started on  Fri May 10 09:03:42 2013 pierre petit
** Last update Fri May 10 09:06:02 2013 pierre petit
*/

#include "server.h"

int	xrecv(int fd, void *buff, size_t len, int flags)
{
  int	st;

  st = recv(fd, buff, len, flags);
  if (st == -1)
    {
      errno = EBADF | EINTR;
      exit_perror("recv");
      return (-1);
    }
  return (st);
}
