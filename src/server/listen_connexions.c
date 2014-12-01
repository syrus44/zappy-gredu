/*
** listen_connexions.c for listen_connexions in /home/bettin_j//ZappySockets/src
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 10:36:12 2013 jordan bettin
** Last update Thu Jul 11 16:56:37 2013 mael charles
*/

#include "server.h"

int	listen_connexions(t_server *srv, t_argument *args)
{
  int	err;

  err = listen(srv->fd_srv, 1024);
  if (err == -1)
    {
      xclose(srv->fd_srv);
      errno = EADDRINUSE | EBADF | EOPNOTSUPP;
      fprintf(stderr, "Max number of clients reached\n");
      return (-1);
    }
  init_fdsets(srv, args);
  return (0);
}
