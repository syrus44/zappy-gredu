/*
** fill_infos_sock.c for fill_infos_sock in /home/bettin_j//ZappySockets/src
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 10:21:03 2013 jordan bettin
** Last update Sat May 18 14:51:19 2013 jordan bettin
*/

#include "server.h"

int	fill_infos_sock(t_server *srv, t_argument *args)
{
  int	st;
  int	on;

  on = 1;
  st = setsockopt(srv->fd_srv, SOL_SOCKET, SO_REUSEADDR,
		  &on, sizeof(on));
  if (st == -1)
    {
      xclose(srv->fd_srv);
      errno = EBADF | EINVAL | ENOTSOCK;
      exit_perror("setsockopt");
      return (-1);
    }
  srv->sin_srv.sin_family = AF_INET;
  srv->sin_srv.sin_port = htons(args->port_number);
  srv->sin_srv.sin_addr.s_addr = INADDR_ANY;
  bind_socket(srv, args);
  return (0);
}
