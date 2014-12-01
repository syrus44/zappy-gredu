/*
** xclose.c for xclose in /home/bettin_j//ZappySockets
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 10:47:06 2013 jordan bettin
** Last update Thu May  9 10:48:24 2013 jordan bettin
*/

#include "server.h"

int	xclose(int fd)
{
  int	st;

  st = close(fd);
  if (st == -1)
    {
      errno = EBADF | EINTR;
      exit_perror("close");
      return (-1);
    }
  return (st);
}
