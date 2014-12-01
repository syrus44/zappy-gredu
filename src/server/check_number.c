/*
** check_number.c for check_number in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 15:35:47 2013 mael charles
** Last update Thu May  9 16:57:36 2013 mael charles
*/

#include "pars.h"

int	check_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (isdigit(str[i]) == 0)
	return (-1);
      i++;
    }
  return (0);
}
