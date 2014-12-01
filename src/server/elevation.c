/*
** elevation.c for  in /home/dugast_a//SystemUnix/zappy/zappy-gredu/branches/Ant
** 
** Made by antoine dugast
** Login   <dugast_a@epitech.net>
** 
** Started on  Wed Jun 19 14:38:01 2013 antoine dugast
** Last update Wed Jun 19 15:31:50 2013 antoine dugast
*/

#include	"players.h"

t_elevation	elev[] =
  {
    {1, &elev1},
    {2, &elev2},
    {3, &elev3},
    {4, &elev4},
    {5, &elev5},
    {6, &elev6},
    {7, &elev7},
    {8, NULL}
  };

void		elevation(t_players *p, t_map *m)
{
  int		i;

  i = 0;
  while (elev[i].lvl != 8)
    {
      if (p->lvl == elev[i].lvl)
        elev[i].fct(p, m);
      i++;
    }
}
