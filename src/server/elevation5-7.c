/*
** elevation4-7.c for  in /home/dugast_a//SystemUnix/zappy/zappy-gredu/branches/Ant
** 
** Made by antoine dugast
** Login   <dugast_a@epitech.net>
** 
** Started on  Wed Jun 19 15:31:54 2013 antoine dugast
** Last update Wed Jun 19 15:40:50 2013 antoine dugast
*/

#include	"players.h"

void		elev5(t_players *p, t_map *m)
{
  (void)m;
  if (p->inv[Linemate] >= 1 &&
      p->inv[Deraumere] >= 2 &&
      p->inv[Sibur] >= 1 &&
      p->inv[Mendiane] >= 3)
    {
      p->inv[Linemate]--;
      p->inv[Deraumere] = p->inv[Deraumere] - 2;
      p->inv[Sibur]--;
      p->inv[Mendiane] = p->inv[Mendiane] - 3;
      p->lvl++;
    }
}

void		elev6(t_players *p, t_map *m)
{
  (void)m;
  if (p->inv[Linemate] >= 1 &&
      p->inv[Deraumere] >= 2 &&
      p->inv[Sibur] >= 3 &&
      p->inv[Phiras] >= 1)
    {
      p->inv[Linemate]--;
      p->inv[Deraumere] = p->inv[Deraumere] - 2;
      p->inv[Sibur] = p->inv[Sibur] - 3;
      p->inv[Phiras]--;
      p->lvl++;
    }
}

void		elev7(t_players *p, t_map *m)
{
  (void)m;
  if (p->inv[Linemate] >= 2 &&
      p->inv[Deraumere] >= 2 &&
      p->inv[Sibur] >= 2 &&
      p->inv[Mendiane] >= 2 &&
      p->inv[Phiras] >= 2 &&
      p->inv[Thystame] >= 1)
    {
      p->inv[Linemate] = p->inv[Linemate] - 2;
      p->inv[Deraumere] = p->inv[Deraumere] - 2;
      p->inv[Sibur] = p->inv[Sibur] - 2;
      p->inv[Phiras] = p->inv[Phiras] - 2;
      p->inv[Thystame]--;
      p->lvl++;
    }
}
