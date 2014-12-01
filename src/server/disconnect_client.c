/*
** disconnect_client.c for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy/src/server
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Thu Jun 20 11:49:15 2013 louis cailleux
** Last update Sun Jul 14 19:22:07 2013 louis cailleux
*/

#include "server.h"

int		clean_list_client(t_client *tmp, t_client *current,
			  t_list *clist, unsigned int i)
{
  tmp = current;
  fflush(stdout);
  printf("Disconnected from: %s\n", inet_ntoa(current->sin_cli.sin_addr));
  if (i == (clist->size - 1))
    {
      clist->end->prev->next = NULL;
      clist->end = current->prev;
    }
  else
    {
      current->prev->next = current->next;
      current->next->prev = current->prev;
    }
  destroy(tmp->player);
  close(tmp->fd_cli);
  free(tmp);
  clist->size--;
  return (0);
}

int		disconnect_client(t_list *clist, int fd)
{
  t_client	*current;
  t_client	*tmp;
  unsigned int	i;

  i = 0;
  current = clist->begin;
  tmp = NULL;
  while (current)
    {
      if (current->fd_cli == fd)
	return (clean_list_client(tmp, current, clist, i));
      ++i;
      current = current->next;
    }
  return (0);
}
