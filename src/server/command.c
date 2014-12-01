/*
** command.c for command.c in /home/charle_b//Desktop/System_unix/Zappy/parse_command
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Sat May 18 16:27:24 2013 mael charles
** Last update Wed Jul 10 10:39:25 2013 mael charles
*/

#include "commpars.h"

int		player_position(char *buff, t_server *serv, int fd, t_list *list)
{
  t_client	*cli;
  int		i;
  int		position;
  int		tmp;

  cli = list->begin;
  i = 0;
  if (count_space(buff, 1) == -1)
    return (-1);
  while (buff[i] && buff[i] != ' ')
    i++;
  i++;
  position = get_player_number(buff, i);
  while (cli)
    {
      if (cli->fd_cli != serv->fd_srv)
	if ((tmp = get_player_position(cli, list, fd, position)) != 1)
	  return (tmp);
      cli = cli->next;
    }
  return (0);
}

int		player_level(char *buff, t_server *serv, int fd, t_list *list)
{
  t_client	*cli;
  int		i;
  int		level;
  int		tmp;

  i = 0;
  cli = list->begin;
  if (count_space(buff, 1) == -1)
    return (-1);
  while (buff[i] && buff[i] != ' ')
    i++;
  i++;
  level = get_player_number(buff, i);
  while (cli)
    {
      if (cli->fd_cli != serv->fd_srv)
	if ((tmp = get_player_lvl(cli, list, fd, level)) != 1)
	  return (tmp);
      cli = cli->next;
    }
  return (0);
}

int		player_invent(char *buff, t_server *serv, int fd, t_list *list)
{
  t_client	*cli;
  int		i;
  int		invent;
  int		tmp;

  i = 0;
  cli = list->begin;
  if (count_space(buff, 1) == -1)
    return (-1);
  while (buff[i] && buff[i] != ' ')
    i++;
  i++;
  invent = get_player_number(buff, i);
  while (cli)
    {
      if (cli->fd_cli != serv->fd_srv)
	if ((tmp = get_player_invent(cli, list, fd, invent)) != 1)
	  return (tmp);
      cli = cli->next;
    }
  return (0);
}

int		mod_time(char *buff, t_server *serv, int fd, t_list *list)
{
  int		i;
  int		time;
  char		*size;

  i = 0;
  if (count_space(buff, 1) == -1)
    return (-1);
  while (buff[i] && buff[i] != ' ')
    i++;
  i++;
  time = get_player_number(buff, i);
  serv->time = time;
  if ((size = malloc(sizeof(char) * 25)) == NULL)
    return (-1);
  sprintf(size, "sgt %li\n", serv->time);
  if (send_command(list, fd, size) == -1)
    return (-1);
  return (0);
}
