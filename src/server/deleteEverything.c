/*
** deleteEverything.c for zappy in /home/caille_l//Documents/ZappySockets/src
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Sat May 11 15:06:07 2013 louis cailleux
** Last update Sun Jul 14 19:22:38 2013 louis cailleux
*/

#include "server.h"

int		deleteEverything(t_server *srv, t_list *clist, t_argument *arg)
{
  t_client	*current;
  char		*end;

  current = clist->begin;
  while (current)
    {
      if (current->fd_cli != srv->fd_srv)
	{
	  if ((end = strdup("seg N\n")) == NULL)
	    return (-1);
	  if (send_command(clist, current->fd_cli, end) == -1)
	    return (-1);
	}
      current = current->next;
    }
  close(srv->fd_srv);
  delete_all(clist);
  free_list(arg);
  free_srv(srv);
  return (0);
}

void		free_srv(t_server *srv)
{
  destroyObject(srv->objects);
  destroyMap(srv->map);
  free(srv->buff->buffer);
  free(srv->buff);
  free(srv);
}
