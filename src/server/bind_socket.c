/*
** bind_socket.c for bind_socket in /home/bettin_j//ZappySockets/src
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 10:23:42 2013 jordan bettin
** Last update Mon Jul  1 09:47:11 2013 jordan bettin
*/

#include "server.h"

int	bind_socket(t_server *srv, t_argument *args)
{
  int	err;

  err = bind(srv->fd_srv, (const struct sockaddr *)&(srv->sin_srv),
	     sizeof(srv->sin_srv));
  if (err == -1)
    {
      xclose(srv->fd_srv);
      errno = EACCES | EADDRINUSE | EBADF | EINVAL | ENOTSOCK;
      fprintf(stderr, "The port is already used\n");
      return (-1);
    }
  listen_connexions(srv, args);
  return (0);
}
