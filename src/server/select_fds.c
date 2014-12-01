/*
** select_fds.c for select_fds in /home/bettin_j//ZappySockets
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 13:45:35 2013 jordan bettin
** Last update Sun Jul 14 19:06:40 2013 louis cailleux
*/

#include <signal.h>
#include "server.h"

void		intHandler(int sig)
{
  signal(sig, SIG_IGN);
  signal(SIGINT, intHandler);
  signal(SIGQUIT, intHandler);
}

int		setmaxfd(t_server *srv, t_list *clist)
{
  t_client	*current;
  int		fd_max;

  fd_max = 0;
  current = clist->begin;
  while (current)
    {
      if (current->fd_cli != 0)
	FD_SET(current->fd_cli, &srv->read_fs);
      if (fd_max < current->fd_cli)
	fd_max = current->fd_cli;
      current = current->next;
    }
  return (fd_max);
}

int		select_fds(t_server *srv, t_list *clist, t_argument *args)
{
  if (initEverything(srv, args) == -1)
    return (-1);
  while (42)
    {
      FD_ZERO(&(srv->read_fs));
      srv->max_fd = setmaxfd(srv, clist);
      if (xselect(srv->max_fd + 1, &(srv->read_fs), NULL,
		  NULL, &(srv->tv)) == -1)
	{
	  deleteEverything(srv, clist, args);
	  return (-1);
	}
      if (FD_ISSET(srv->fd_srv, &(srv->read_fs)))
	accept_connexions(srv, clist);
      send_receive(srv, clist);
    }
  if (signal(SIGINT, intHandler) == SIG_IGN ||
      signal(SIGQUIT, intHandler) == SIG_IGN)
    {
      deleteEverything(srv, clist, args);
      return (-1);
    }
  return (0);
}
