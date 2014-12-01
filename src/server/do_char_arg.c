/*
** do_char_arg.c for do_char_arg in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 11:47:29 2013 mael charles
** Last update Sun Jul 14 19:21:29 2013 louis cailleux
*/

#include "pars.h"

int	count_arg(char **av)
{
  int	i;
  int	nb;

  i = 1;
  nb = 0;
  while (av[i])
    {
      nb += strlen(av[i]);
      i++;
    }
  return (nb);
}

char	*concat(char **av, int i)
{
  char	*arg;

  if ((arg = malloc(sizeof(char) * (count_arg(av) + 1))) == NULL)
    return (0);
  if (strcpy(arg, av[i]) == 0)
    return (0);
  i++;
  while (av[i])
    {
      if (strcat(arg, " ") == 0)
	return (0);
      if (strcat(arg, av[i]) == 0)
	return (0);
      if (av[i + 1] && av[i + 1][0] == '-')
	{
	  arg[(strlen(arg) + 1)] = '\0';
	  return (arg);
	}
      i++;
    }
  arg[(strlen(arg) + 1)] = '\0';
  return (arg);
}

void	init_struct(t_argument *argstruct)
{
  argstruct->port_number = -1;
  argstruct->width = -1;
  argstruct->height = -1;
  argstruct->number_clients = -1;
  argstruct->time_action = -1;
  argstruct->team = NULL;
}

int	do_char_arg_next(char **av, t_argument *argstruct, int i, char *tmp)
{
  if ((tmp = concat(av, i)) == 0)
    return (-1);
  if (argpars(tmp, argstruct) == -1)
    {
      free(tmp);
      return (-1);
    }
  return (1);
}

int	do_char_arg(char **av, t_argument *argstruct)
{
  int	i;
  int	err;
  char	*tmp;

  i = 1;
  err = 0;
  tmp = NULL;
  init_struct(argstruct);
  if (check_miniarg(av) == -1)
    return (-1);
  while (av[i] != 0)
    {
      if (av[i][0] == '-')
	{
	  if ((err = do_char_arg_next(av, argstruct, i, tmp)) == -1)
	    return (-1);
	}
      i++;
    }
  if (err == 0)
    {
      printf(INV_CMD);
      return (-1);
    }
  return (0);
}
