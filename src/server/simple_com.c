/*
** simple_com.c for simple_com in /home/charle_b//Desktop/System_unix/Zappy/parse_command
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Wed Jun 12 13:35:34 2013 mael charles
** Last update Sun Jul 14 19:08:51 2013 louis cailleux
*/

#include "commpars.h"

int	size_map(char *buff, t_server *serv, int fd, t_list *list)
{
  char	*size;

  (void)buff;
  if ((size = malloc(sizeof(char) * 25)) == NULL)
    return (-1);
  sprintf(size, "msz %d %d\n", serv->map->max_x, serv->map->max_y);
  if (send_command(list, fd, size) == -1)
    return (-1);
  return (0);
}

int	pa_team(char *buff, t_server *serv, int fd, t_list *list)
{
  char	*size;
  int	i;

  (void)buff;
  (void)list;
  i = 0;
  while (serv->all_team[i])
    {
      if ((size = malloc(sizeof(char) * 25)) == NULL)
	return (-1);
      sprintf(size, "tna %s\n", serv->all_team[i]);
      if (send_command(list, fd, size) == -1)
	return (-1);
      i++;
    }
  return (0);
}

int	cont_map(char *buff, t_server *serv, int fd, t_list *list)
{
  (void)buff;
  if (send_map(list, serv, fd) == -1)
    return (-2);
  return (0);
}

int	get_time(char *buff, t_server *serv, int fd, t_list *list)
{
  char	*size;

  (void)buff;
  if ((size = malloc(sizeof(char) * 25)) == NULL)
    return (-1);
  sprintf(size, "sgt %li\n", serv->time);
  if (send_command(list, fd, size) == -1)
    return (-1);
  return (0);
}
