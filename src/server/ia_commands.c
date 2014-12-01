/*
** ia_commands.c for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Mon Jul  1 12:50:18 2013 louis cailleux
** Last update Sun Jul 14 19:17:49 2013 louis cailleux
*/

#include "commpars.h"

int	ia_pickres(char *buff, t_server *srv, int fd, t_list *list)
{
  char	*tmp;
  int	*s;

  tmp = epur_str(buff);
  if ((s = handle_tab(tmp, 0, 0)) == NULL)
    return (-1);
  gettimeofday(&get_client(list, fd)->player->start, NULL);
  gettimeofday(&get_client(list, fd)->player->end, NULL);
  time_ia_action(list, fd, srv->time, 7.00);
  if (map_modif(extract_number(tmp, s[0]), extract_number(tmp, s[1]),
		extract_number(tmp, s[2]), srv) == -1)
    {
      free(s);
      free(tmp);
      return (-1);
    }
  if (pick_buf(srv, list, extract_number(tmp, s[0]), fd) == -1)
    {
      free(s);
      free(tmp);
      return (-1);
    }
  free(s);
  free(tmp);
  return (0);
}

int	*handle_tab(char *tmp, int i, int j)
{
  int	*s;

  if ((s = malloc(sizeof(int) * 4)) == NULL)
    return (NULL);
  while (tmp[i])
    {
      if (tmp[i] == ' ' && tmp[i + 1])
	{
	  s[j] = i + 1;
	  ++j;
	}
      ++i;
    }
  if (j < 3)
    {
      free(tmp);
      free(s);
      return (NULL);
    }
  return (s);
}

int	pick_buf(t_server *srv, t_list *list, int res, int fd)
{
  char	*buf;

  if ((buf = malloc(sizeof(char) * 25)) == NULL)
    return (-1);
  gettimeofday(&get_client(list, fd)->player->start, NULL);
  gettimeofday(&get_client(list, fd)->player->end, NULL);
  time_ia_action(list, fd, srv->time, 7.00);
  if (sprintf(buf, "pgt %d %d\n", get_client(list, fd)->player->id, res) == -1)
    return (-1);
  if (send_modif(list, srv, buf) == -1)
    return (-1);
  return (0);
}

int	ia_move(char *buff, t_server *srv, int fd, t_list *list)
{
  int	l;
  int	sp;
  int	j;
  char	*buf;

  if ((buf = malloc(sizeof(char *) * 25)) == NULL)
    return (-1);
  gettimeofday(&get_client(list, fd)->player->start, NULL);
  l = 0;
  j = 0;
  while (buff[l])
    {
      if (buff[l] == ' ')
	{
	  if (j == 1)
	    sp = l + 1;
	  ++j;
	}
      ++l;
    }
  sprintf(buf, "ppo %d %s", get_client(list, fd)->player->id, &buff[sp]);
  if (send_modif(list, srv, buf) == -1)
    return (-1);
  gettimeofday(&get_client(list, fd)->player->end, NULL);
  return (time_ia_action(list, fd, srv->time, 7.00));
}

int	ia_lvlup(char *buff, t_server *srv, int fd, t_list *list)
{
  char	*buf;

  (void)buff;
  if ((buf = malloc(sizeof(char *) * 25)) == NULL)
    return (-1);
  gettimeofday(&get_client(list, fd)->player->start, NULL);
  gettimeofday(&get_client(list, fd)->player->end, NULL);
  time_ia_action(list, fd, srv->time, 300.00);
  get_client(list, fd)->player->lvl++;
  sprintf(buf, "plv %d %d\n", get_client(list, fd)->player->id,
	  get_client(list, fd)->player->lvl);
  if (send_modif(list, srv, buf) == -1)
    return (-1);
  return (0);
}
