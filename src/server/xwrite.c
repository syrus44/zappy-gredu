/*
** xwrite.c for xwrite in /home/bettin_j//ZappySockets
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 10:49:48 2013 jordan bettin
** Last update Sun Jul 14 19:07:05 2013 louis cailleux
*/

#include "server.h"

int	xwrite(int fd, const void *buff, size_t count)
{
  int	wd;

  wd = write(fd, buff, count);
  if (wd < 0)
    {
      errno = EBADF | EPIPE | EINVAL;
      exit_perror("write");
      return (-1);
    }
  return (wd);
}
