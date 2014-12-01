/*
** create_socket.c<2> for create_socket in /home/bettin_j//ZappySockets/src
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 10:17:50 2013 jordan bettin
** Last update Sun Jul 14 19:22:48 2013 louis cailleux
*/

#include "server.h"

int		create_socket(struct protoent *pe, t_argument *args)
{
  t_server	*srv;

  srv = xmalloc(sizeof(t_server));
  srv->fd_srv = socket(PF_INET, SOCK_STREAM, pe->p_proto);
  if (srv->fd_srv == -1)
    {
      errno = EINVAL | EPROTONOSUPPORT | EACCES;
      fprintf(stderr, "Invalid port number or socket already created\n");
      return (-1);
    }
  fill_infos_sock(srv, args);
  return (0);
}
