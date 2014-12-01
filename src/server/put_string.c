/*
** put_string.c for put_string in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 17:47:50 2013 mael charles
** Last update Fri May 10 09:46:38 2013 mael charles
*/

#include "pars.h"

void	put_string(char *str, char *tab, int i)
{
  int	j;

  j = 0;
  while (str[i] && str[i] != ' ')
    {
      tab[j] = str[i];
      i++;
      j++;
    }
  str[i] = '\0';
}
