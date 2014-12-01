/*
** count_word.c for count_word in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 17:21:28 2013 mael charles
** Last update Fri May 10 17:45:10 2013 mael charles
*/

#include "pars.h"

int	count_word(char *str)
{
  int	space;
  int	i;

  i = 0;
  space = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	space++;
      i++;
    }
  space++;
  return (space);
}
