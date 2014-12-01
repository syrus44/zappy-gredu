/*
** xread.c for  in /home/petit_p//projets/Zappy/zappy-gredu/trunk/sparw
** 
** Made by pierre petit
** Login   <petit_p@epitech.net>
** 
** Started on  Fri May 10 09:33:34 2013 pierre petit
** Last update Fri May 10 09:35:22 2013 pierre petit
*/

#include "server.h"

int	xread(int fd, void *buff, size_t len)
{
  int	st;

  st = read(fd, buff, len);
  if (st == -1)
    {
      errno = EBADF | EPIPE | EINVAL;
      exit_perror("read");
      return (-1);
    }
  return (st);
}
