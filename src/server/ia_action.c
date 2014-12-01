/*
** ia_move.c for zappy in /home/farcy_j//zappy-gredu/trunk/Zappy/src/server
** 
** Made by jimmy farcy
** Login   <farcy_j@epitech.net>
** 
** Started on  Wed Jul 10 19:36:19 2013 jimmy farcy
** Last update Sun Jul 14 19:18:24 2013 louis cailleux
*/

#include	"commpars.h"

long int	get_diff_time(struct timeval start, struct timeval end)
{
  long int 	result;
  long int	sstart;
  long int	send;

  sstart = end.tv_sec * 1000000 + end.tv_usec;
  send = start.tv_sec * 1000000 + start.tv_usec;
  result = sstart - send;
  return (result);
}

int		get_time_cmd(float num, float time)
{
  float		tmp;
  int		result;

  tmp = num / time;
  tmp *= 1000000;
  result = tmp;
  return (result);
}

int		time_ia_action(t_list *list, int fd, long time, float ratio)
{
  long int	j;
  int		i;

  i = 0;
  j = 0;
  if ((j = get_diff_time(get_client(list, fd)->player->start
			 , get_client(list, fd)->player->end))
      < get_time_cmd(ratio, time))
    while (j < get_time_cmd(ratio, time))
      {
	if (i % 5 == 0)
	  {
	    gettimeofday(&get_client(list, fd)->player->end, NULL);
	    j = get_diff_time(get_client(list, fd)->player->start,
			      get_client(list, fd)->player->end);
	  }
	i++;
      }
  return (0);
}
