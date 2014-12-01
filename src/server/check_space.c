/*
** check_space.c for check_space in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 15:00:08 2013 mael charles
** Last update Thu May  9 15:12:30 2013 mael charles
*/

#include "pars.h"

int	check_space(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	nb++;
      i++;
    }
  return (nb);
}
