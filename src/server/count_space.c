/*
** count_space.c for count_space in /home/charle_b//Desktop/System_unix/Zappy/parse_command
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu Jun 13 18:09:01 2013 mael charles
** Last update Thu Jun 13 18:11:07 2013 mael charles
*/

#include "commpars.h"

int	count_space(char *buff, int nb)
{
  int	i;
  int	tmp_nb;

  i = 0;
  tmp_nb = 0;
  while (buff[i])
    {
      if (buff[i] == ' ')
	tmp_nb++;
      i++;
    }
  if (tmp_nb != nb)
    return (-1);
  return (0);
}
