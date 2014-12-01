/*
** client_list.c for zappy in /home/caille_l//Documents/ZappySockets
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Fri May 10 14:11:31 2013 louis cailleux
** Last update Sun Jul 14 19:25:15 2013 louis cailleux
*/

#include "server.h"

int		add_empty(t_list *list, t_server *srv,
			  t_client *client)
{
  t_players	*player;

  if ((client = malloc(sizeof(t_client))) == NULL)
    return (-1);
  if ((player = malloc(sizeof(t_players))) == NULL)
    return (-1);
  init(player);
  player->setname(player, "server");
  client->player = player;
  client->fd_cli = srv->fd_srv;
  client->is_grap = 0;
  client->player->time_server = srv->time;
  list->begin = client;
  list->end = client;
  list->size++;
  list->begin->next = NULL;
  list->begin->prev = NULL;
  return (0);
}

int		add_end(t_list *list, t_client *client, int id, t_server *srv)
{
  t_players	*player;

  if ((player = malloc(sizeof(t_players))) == NULL)
    return (-1);
  init(player);
  player->fd = client->fd_cli;
  player->lvl = 1;
  player->id = id;
  player->setInventory(player);
  client->player = player;
  client->is_grap = 0;
  client->player->time_server = srv->time;
  client->next = NULL;
  client->prev = list->end;
  list->end->next = client;
  list->end = client;
  list->size++;
  return (0);
}

void		show_list(t_list *list)
{
  t_client	*current;

  current = list->begin;
  while (current)
    {
      printf("%d\n", current->fd_cli);
      current = current->next;
    }
}

void		delete_all(t_list * list)
{
  t_client	*current;
  t_client	*tmp;

  current = list->begin;
  while (current)
    {
      tmp = current;
      current = current->next;
      close(tmp->fd_cli);
      destroy(tmp->player);
      free(tmp);
      list->size--;
    }
}

t_client	*get_client(t_list *list, int fd)
{
  t_client	*current;

  current = list->begin;
  while (current)
    {
      if (current->fd_cli == fd)
	return (current);
      current = current->next;
    }
  return (NULL);
}
