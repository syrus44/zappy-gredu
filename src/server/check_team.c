/*
** check_team.c for check_team in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Fri May 10 11:55:18 2013 mael charles
** Last update Fri May 10 17:21:10 2013 mael charles
*/

#include "pars.h"

int	check_teamname(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (isalpha(str[i]) || isdigit(str[i]) || str[i] == '_')
	i++;
      else
	{
	  printf(INV_TEAMNAME);
	  return (-1);
	}
    }
  return (0);
}

int	check_team(char **tab)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (tab[i])
    {
      if (check_teamname(tab[i]) == -1)
	return (-1);
      while (tab[j])
	{
	  if (j != i && (strcmp(tab[i], tab[j]) == 0))
	    {
	      printf(MULTI_TEAM);
	      return (-1);
	    }
	  j++;
	}
      j = 0;
      i++;
    }
  return (0);
}
