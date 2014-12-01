/*
** argpars.c for argpars in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 10:04:42 2013 mael charles
** Last update Sun Jul 14 17:05:48 2013 mael charles
*/

#include "pars.h"

struct s_arg	tab[] =
  {
    {"-p ", port_number},
    {"-x ", width},
    {"-y ", height},
    {"-n ", init_team},
    {"-c ", number_clients},
    {"-t ", time_action},
    {NULL, NULL},
  };

int		argpars(char *av, t_argument *argstruct)
{
  int		i;
  int		err;

  i = 0;
  err = 0;
  while (tab[i].arg != NULL)
    {
      if (strncmp(av, tab[i].arg, 3) == 0)
	{
	  err = 1;
	  if (tab[i].exec(av, argstruct) == -1)
	    return (-1);
	}
      i++;
    }
  if (err == 0)
    {
      printf(INV_ARG);
      return (-1);
    }
  free(av);
  return (0);
}
