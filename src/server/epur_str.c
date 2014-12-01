/*
** epur_str.c for epur_str in /home/charle_b//Desktop/System_unix/Zappy/parse_command
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu Jun 13 16:58:25 2013 mael charles
** Last update Wed Jul 10 00:45:01 2013 louis cailleux
*/

#include "commpars.h"

int	count_epu(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i])
    {
      if (str[i] && (str[i] == ' ' || str[i] == '\t'))
	{
	  nb++;
	  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	    i++;
	}
      nb++;
      i++;
    }
  return (nb);
}

int	move_iterator(char *buff, int i)
{
  while (buff[i] && (buff[i] == ' ' || buff[i] == '\t'))
    i++;
  return (i);
}

char	*epur_str(char *buff)
{
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((str = malloc(sizeof(char) * (count_epu(buff) + 1))) == NULL)
    return (0);
  while (buff[i])
    {
      if (buff[i] && (buff[i] == ' ' || buff[i] == '\t'))
	{
	  i = move_iterator(buff, i);
	  if (buff[i] != '\n')
	    {
	      str[j] = ' ';
	      j++;
	    }
	}
      str[j] = buff[i];
      i++;
      j++;
    }
  str[j] = '\0';
  return (str);
}
