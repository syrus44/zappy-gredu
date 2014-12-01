/*
** init_clients.c for init_clients in /home/bettin_j//ZappySockets/src
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 12:02:18 2013 jordan bettin
** Last update Sun Jul 14 19:17:07 2013 louis cailleux
*/

#include "server.h"

int	init_clients(t_server *srv, t_client *cli)
{
  cli = xmalloc(sizeof(t_client));
  if (cli == NULL)
    {
      xclose(srv->fd_srv);
      xwrite(2, ERR_CLI, strlen(ERR_CLI));
      return (-1);
    }
  return (0);
}
