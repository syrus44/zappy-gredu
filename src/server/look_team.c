/*
** look_team.c for look_team in /home/charle_b//Dropbox/Zappy-test/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Mon Jul  8 12:03:55 2013 mael charles
** Last update Sun Jul 14 19:16:41 2013 louis cailleux
*/

#include "commpars.h"

int		valid_team(char *buff, t_server *serv, int fd, t_list *clist)
{
  int		i;
  int		valid;
  char		*size;

  i = 0;
  valid = 0;
  while (serv->all_team[i])
    {
      if (strncmp(serv->all_team[i], buff, strlen(buff) - 1) == 0)
	valid = 1;
      i++;
    }
  if (valid == 1)
    return (0);
  else
    {
      if ((size = strdup("tco\n")) == NULL)
	return (-1);
      if (send_command(clist, fd, size) == -1)
	return (-1);
    }
  return (0);
}

int		look_team(char *buff, t_server *serv, int fd, t_list *list)
{
  t_client	*cli;

  (void)serv;
  (void)fd;
  cli = list->begin;
  if (count_space(buff, 1) == -1)
    return (-1);
  while (*buff != ' ')
    buff++;
  buff++;
  if (valid_team(buff, serv, fd, list) == -1)
    return (-1);
  while (cli)
    {
      if (cli->fd_cli != serv->fd_srv)
	{
	  if (cli->player->team_name == NULL)
	    {
	      cli->player->setTeam(cli->player, buff);
	      return (0);
	    }
	}
      cli = cli->next;
    }
  return (0);
}
