/*
** send_map.c for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Wed Jun 12 20:18:06 2013 louis cailleux
** Last update Sun Jul 14 19:11:56 2013 louis cailleux
*/

#include <string.h>
#include <unistd.h>
#include "server.h"

int	send_map(t_list *clist, t_server *srv, int fd)
{
  char	*size;

  if ((size = malloc(sizeof(char) * 22)) == NULL)
    return (-1);
  sprintf(size, "msz %d %d\n", srv->map->max_x, srv->map->max_y);
  if (send_command(clist, fd, size) == -1)
    return (-1);
  if (srv->map->serialize)
    if (send(fd, srv->map->serial, strlen(srv->map->serial), 0) <= 0)
      {
	disconnect_client(clist, fd);
	return (-1);
      }
  return (0);
}

int     welcome(t_server *srv, t_list *clist)
{
  char	*welcome;

  (void)srv;
  if ((welcome = strdup("BIENVENUE\n")) == NULL)
    return (-1);
  if (send_command(clist, clist->end->fd_cli, welcome) == -1)
    return (-1);
  return (0);
}
