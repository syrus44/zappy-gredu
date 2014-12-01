/*
** check_port.c for check_port in /home/bettin_j//ZappySockets
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 10:52:24 2013 jordan bettin
** Last update Thu May  9 10:52:31 2013 jordan bettin
*/

#include "server.h"

int	check_port(char *arg)
{
  int	i;
  int	port;

  i = 0;
  while (arg[i] != '\0')
    {
      if (isdigit(arg[i]) == 0)
	{
	  xwrite(2, ERR_PORT, strlen(ERR_PORT));
	  exit(EXIT_FAILURE);
	}
      i++;
    }
  port = atoi(arg);
  return (port);
}
