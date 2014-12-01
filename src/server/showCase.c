/*
** showMap.c for  in /home/dugast_a//SystemUnix/upzappy/zappy-gredu/branches/IA
** 
** Made by antoine dugast
** Login   <dugast_a@epitech.net>
** 
** Started on  Thu Jun 13 14:41:23 2013 antoine dugast
** Last update Sun Jul 14 19:09:10 2013 louis cailleux
*/

#include	"players.h"

void		showCase(int *c)
{
  int		i;

  i = 0;
  while (i != 5)
    {
      printf("%d", c[i]);
      i++;
    }
  printf("\n");
}
