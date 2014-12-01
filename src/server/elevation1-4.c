/*
** elevation1-3.c for  in /home/dugast_a//SystemUnix/zappy/zappy-gredu/branches/Ant
** 
** Made by antoine dugast
** Login   <dugast_a@epitech.net>
** 
** Started on  Wed Jun 19 15:29:35 2013 antoine dugast
** Last update Wed Jun 19 15:40:03 2013 antoine dugast
*/

#include	"players.h"

void		elev1(t_players *p, t_map *m)
{
  (void)m;
  if (p->inv[Linemate] >= 1)
    {
      p->inv[Linemate]--;
      p->lvl++;
    }
}

void		elev2(t_players *p, t_map *m)
{
  (void)m;
  if (p->inv[Linemate] >= 1 &&
      p->inv[Deraumere] >= 1 &&
      p->inv[Sibur] >= 1)
    {
      p->inv[Linemate]--;
      p->inv[Deraumere]--;
      p->inv[Sibur]--;
      p->lvl++;
    }
}

void		elev3(t_players *p, t_map *m)
{
  (void)m;
  if (p->inv[Linemate] >= 2 &&
      p->inv[Sibur] >= 1 &&
      p->inv[Phiras] >= 2)
    {
      p->inv[Linemate] = p->inv[Linemate] - 2;
      p->inv[Sibur]--;
      p->inv[Phiras] = p->inv[Phiras] - 2;
      p->lvl++;
    }
}

void		elev4(t_players *p, t_map *m)
{
  (void)m;
  if (p->inv[Linemate] >= 1 &&
      p->inv[Deraumere] >= 1 &&
      p->inv[Sibur] >= 2 &&
      p->inv[Phiras] >= 1)
    {
      p->inv[Linemate]--;
      p->inv[Deraumere]--;
      p->inv[Sibur] = p->inv[Sibur] - 2;
      p->inv[Phiras]--;
      p->lvl++;
    }
}
