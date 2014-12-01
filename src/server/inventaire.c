/*
** inventaire.c for  in /home/dugast_a//SystemUnix/zappy/zappy-gredu/branches/Ant
** 
** Made by antoine dugast
** Login   <dugast_a@epitech.net>
** 
** Started on  Thu Jun 20 09:19:00 2013 antoine dugast
** Last update Thu Jun 20 09:19:51 2013 antoine dugast
*/

#include	"players.h"

void		showInv(t_players *p)
{
  int		i;

  i = 0;
  while (i != 7)
    {
      printf("case [%d] = %d\n", i, p->inv[i]);
      i++;
    }
  printf("\n");
}
