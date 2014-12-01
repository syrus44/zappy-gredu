/*
** main.c for main in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 09:42:58 2013 mael charles
** Last update Sun Jul 14 19:15:59 2013 louis cailleux
*/

#include "server.h"

int		main(int ac, char **av)
{
  t_argument	*argstruct;

  if (ac >= 12)
    {
      if ((argstruct = malloc(sizeof(t_argument) + count_arg(av))) == NULL)
	return (-1);
      if (do_char_arg(av, argstruct) <= -1)
	{
	  free_struct(argstruct);
	  return (EXIT_FAILURE);
	}
      if (receive_args(argstruct) == -1)
	return (EXIT_FAILURE);
    }
  else
    {
      fprintf(stderr, USAGE);
      fprintf(stderr, USAGE_SUITE);
      return (printFailure(USAGE_END));
    }
  return (EXIT_SUCCESS);
}
