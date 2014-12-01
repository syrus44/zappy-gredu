/*
** init_fdsets.c for init_fdsets in /home/bettin_j//ZappySockets/src
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 11:49:36 2013 jordan bettin
** Last update Thu Jul 11 19:19:07 2013 louis cailleux
*/

#include "server.h"

int		init_fdsets(t_server *srv, t_argument *args)
{
  t_list	clist;
  t_client	cli;

  init_list(&clist);
  srv->max_fd = srv->fd_srv;
  srv->tv.tv_sec = 100;
  srv->tv.tv_usec = 0;
  srv->time = args->time_action;
  srv->all_team = args->team;
  if ((srv->buff = init_buffer()) == NULL)
    return (-1);
  if (add_empty(&clist, srv, &cli) == -1)
    return (-1);
  select_fds(srv, &clist, args);
  return (0);
}
