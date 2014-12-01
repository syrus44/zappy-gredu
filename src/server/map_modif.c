/*
** map_modif.c for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Thu Jun 13 14:42:49 2013 louis cailleux
** Last update Sat Jul 13 18:49:40 2013 louis cailleux
*/

#include "server.h"

int	 map_modif(int res, int x, int y, t_server *srv)
{
  int	i;

  i = 0;
  while (i < 5)
    {
      if (srv->map->map[x][y][i] == res)
	srv->map->map[x][y][i] = 7;
      ++i;
    }
  return (0);
}

int	send_modif(t_list *clist, t_server *srv, char *buf)
{
  if (srv->fd_grap != -1)
    {
      if (send_command(clist, srv->fd_grap, buf) == -1)
	{
	  srv->grap_set = 0;
	  srv->fd_grap = -1;
	  return (-1);
	}
    }
  return (0);
}
