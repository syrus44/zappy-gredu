/*
** check_neg.c for check_neg in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Fri May 10 16:34:16 2013 mael charles
** Last update Fri May 10 16:50:56 2013 mael charles
*/

#include "pars.h"

int	check_neg(char *str)
{
  if (str[0] == '-')
    {
      str++;
      if (check_number(str) == -1)
	{
	  printf(INV_NBR);
	  return (-1);
	}
      printf(INV_NEG);
      return (-1);
    }
  return (0);
}
