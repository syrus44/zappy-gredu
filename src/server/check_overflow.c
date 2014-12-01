/*
** check_overflow.c for check_overflow in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Fri May 10 14:09:01 2013 mael charles
** Last update Fri May 10 17:29:41 2013 mael charles
*/

#include "pars.h"

int	check_overflow(char *str)
{
  int	i;
  char	*char_int;

  i = 0;
  char_int = "2147483647";
  if (strlen(str) > 10)
    {
      printf(INV_NB);
      return (-1);
    }
  else if (strlen(str) == 10)
    {
      while (str[i])
	{
	  if (str[i] > char_int[i])
	    {
	      printf(INV_NB);
	      return (-1);
	    }
	  i++;
	}
    }
  return (0);
}
