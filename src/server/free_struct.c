/*
** free_struct.c for free_struct in /home/charle_b//zappy-gredu/trunk
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Sun Jul 14 16:23:51 2013 mael charles
** Last update Sun Jul 14 17:28:10 2013 mael charles
*/

#include "pars.h"

void	free_struct(t_argument *arg)
{
  int	i;

  i = 0;
  if (arg->team)
    {
      while (arg->team[i])
	{
	  free(arg->team[i]);
	  i++;
	}
      free(arg->team);
    }
  free(arg);
}
