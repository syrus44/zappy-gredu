/*
** count_char.c for count char$ in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 17:36:02 2013 mael charles
** Last update Fri May 10 17:46:21 2013 mael charles
*/

#include "pars.h"

int	count_char(char *str, int i)
{
  int	nb;

  nb = 0;
  while (str[i] && str[i] != ' ')
    {
      i++;
      nb++;
    }
  return (nb);
}
