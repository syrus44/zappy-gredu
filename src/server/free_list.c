/*
** free_list.c for zappy in /home/caille_l//Documents/charle_b
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Sat May 18 12:04:59 2013 louis cailleux
** Last update Sun Jul 14 19:19:50 2013 louis cailleux
*/

#include <stdlib.h>
#include "pars.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	{
	  free(tab[i]);
	  i++;
	}
    }
  free(tab);
}

void	free_list(t_argument *argstruct)
{
  free_tab(argstruct->team);
  free(argstruct);
}
