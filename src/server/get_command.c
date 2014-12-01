/*
** get_command.c for zappy in /home/farcy_j//Templates/zappy-gredu/trunk/Zappy/src/server
** 
** Made by jimmy farcy
** Login   <farcy_j@epitech.net>
** 
** Started on  Wed Jul 10 00:27:29 2013 jimmy farcy
** Last update Sun Jul 14 19:29:30 2013 louis cailleux
*/

#include <stdlib.h>
#include "commpars.h"

int	get_player_position(t_client *cli, t_list *list, int fd, int position)
{
  char	*size;

  if (cli->player->id == position)
    {
      if ((size = malloc(sizeof(char) * 25)) == NULL)
	return (-1);
      sprintf(size, "ppo %d %d %d %d\n", cli->player->id,
	      cli->player->pos_x, cli->player->pos_y, cli->player->d);
      if (send_command(list, fd, size) == -1)
	return (-1);
      return (0);
    }
  return (1);
}

int	get_player_lvl(t_client *cli, t_list *list, int fd, int level)
{
  char	*size;

  if (cli->player->id == level)
    {
      if ((size = malloc(sizeof(char) * 25)) == NULL)
	return (-1);
      sprintf(size, "plv %d %d\n", cli->player->id, cli->player->lvl);
      if (send_command(list, fd, size) == -1)
	return (-1);
      return (0);
    }
  return (1);
}

int	get_player_invent(t_client *cli, t_list *list, int fd, int invent)
{
  char	*size;

  if (cli->player->id == invent)
    {
      gettimeofday(&get_client(list, fd)->player->start, NULL);
      if ((size = malloc(sizeof(char) * 25)) == NULL)
	return (-1);
      sprintf(size, "pin %d %d %d %d %d %d %d %d %d %d\n", cli->player->id,
	      cli->player->pos_x, cli->player->pos_y, cli->player->inv[0],
	      cli->player->inv[1], cli->player->inv[2], cli->player->inv[3],
	      cli->player->inv[4], cli->player->inv[5], cli->player->inv[6]);
      if (send_command(list, fd, size) == -1)
	return (-1);
      gettimeofday(&get_client(list, fd)->player->end, NULL);
      return (time_ia_action(list, fd, cli->player->time_server, 1.00));
    }
  return (1);
}
