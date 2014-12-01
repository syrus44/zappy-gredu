/*
** accept_connexions.c for accept_connexions in /home/bettin_j//ZappySockets
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 13:51:12 2013 jordan bettin
** Last update Fri Jul 12 20:33:00 2013 louis cailleux
*/

#include	"server.h"

int		accept_connexions(t_server *srv, t_list *clist)
{
  socklen_t	len;
  t_client	*cli;

  if ((cli = malloc(sizeof(t_client))) == NULL)
    return (-1);
  len = sizeof(cli->sin_cli);
  cli->fd_cli = accept(srv->fd_srv, (struct sockaddr *)&(cli->sin_cli),
		       &len);
  if (cli->fd_cli == -1)
    {
      errno = EBADF | EPROTO | ENOTSOCK | EINVAL | ECONNABORTED;
      free(cli);
      exit_perror("accept");
    }
  print_ip(cli->sin_cli);
  add_end(clist, cli, srv->id, srv);
  if (welcome(srv, clist) == -1)
    return (-1);
  return (0);
}
