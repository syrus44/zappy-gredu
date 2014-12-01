/*
** extract_number.c for extract_number in /home/charle_b//Desktop/System_unix/Zappy/parse_command
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Wed Jun 12 09:45:51 2013 mael charles
** Last update Thu Jun 13 16:57:43 2013 mael charles
*/

#include "commpars.h"

int	count_number(char *buff, int i)
{
  while (buff[i] && buff[i] >= '0' && buff[i] <= '9')
    i++;
  return (i);
}

int	extract_number(char *buff, int i)
{
  char	*number;
  int	j;
  int	res;

  j = 0;
  if ((number = malloc(sizeof(char) * count_number(buff, i))) == NULL)
    return (0);
  while (buff[i] && buff[i] >= '0' && buff[i] <= '9')
    {
      number[j] = buff[i];
      i++;
      j++;
    }
  number[j] = '\0';
  if (buff[i] != ' ' && buff[i] != '\n' && buff[i] != '\0')
    {
      free(number);
      return (-1);
    }
  if (check_overflow(number) == -1)
    return (-1);
  res = atoi(number);
  free(number);
  return (res);
}
