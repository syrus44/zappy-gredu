/*
** check_miniarg.c for check_miniarg in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Fri May 10 15:00:57 2013 mael charles
** Last update Wed Jul 10 00:22:36 2013 jimmy farcy
*/

#include "pars.h"

int	check_miniarg(char **av)
{
  int	j;
  int	i;
  int	nb;
  char	*arg;

  i = 0;
  j = 0;
  nb = 0;
  arg = "pxynct";
  while (arg[i])
    {
      while (av[j])
	{
	  if (av[j][0] == '-' && av[j][1] == arg[i] && av[j][2] == '\0')
	    nb++;
	  j++;
	}
      if (nb > 1)
	return (printFailure(INV_MULTI_ARG));
      nb = 0;
      j = 0;
      i++;
    }
  return (0);
}
