/*
** xsend.c for  in /home/petit_p//projets/Zappy/zappy-gredu/trunk/sparw
** 
** Made by pierre petit
** Login   <petit_p@epitech.net>
** 
** Started on  Fri May 10 08:56:42 2013 pierre petit
** Last update Fri May 10 09:04:22 2013 pierre petit
*/

#include "server.h"

int	xsend(int fd, const void *buff, size_t len, int flags)
{
  int	st;

  st = send(fd, buff, len, flags);
  if (st == -1)
    {
      errno = EBADF | EINTR;
      exit_perror("send");
      return (-1);
    }
  return (st);
}
