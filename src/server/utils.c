/*
** utils.c for zappy in /home/farcy_j//Templates/zappy-gredu/trunk/Zappy/src/server
** 
** Made by jimmy farcy
** Login   <farcy_j@epitech.net>
** 
** Started on  Wed Jul 10 00:22:42 2013 jimmy farcy
** Last update Wed Jul 10 01:12:42 2013 louis cailleux
*/

#include "pars.h"
#include "objects.h"

int	printFailure(char *str)
{
  fprintf(stderr, str);
  return (-1);
}

void	destroyObject(t_objects *this)
{
  free(this);
}
