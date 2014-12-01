/*
** players.c for  in /home/dugast_a//SystemUnix/upzappy/zappy-gredu/branches/IA
** 
** Made by antoine dugast
** Login   <dugast_a@epitech.net>
** 
** Started on  Thu Jun 13 13:51:35 2013 antoine dugast
** Last update Wed Jul 10 01:09:42 2013 louis cailleux
*/

#include	"players.h"

extern int	setInventory(t_players *this);
extern void	setlevel(t_players *this, int l);
extern void	setname(t_players *this, char *name);
extern void	setTeam(t_players *this, char *team);

extern int	setInventory(t_players *this)
{
  int		i;

  i = 0;
  if ((this->inv = malloc(sizeof(int) * (ITEM_KIND))) == NULL)
    return (-1);
  while (i < ITEM_KIND)
    {
      this->inv[i] = 0;
      ++i;
    }
  return (0);
}

extern void	setlevel(t_players *this, int l)
{
  if (this == NULL)
    return ;
  this->lvl = l;
}

extern void	setname(t_players *this, char *name)
{
  if (this == NULL)
    return ;
  if ((this->name = strdup(name)) == NULL)
    return ;
}

extern void	setTeam(t_players *this, char *team)
{
  if (this == NULL)
    return ;
  if ((this->team_name = strdup(team)) == NULL)
    return ;
}

extern void	setmsg(t_players *this, char *msg)
{
  if (this == NULL)
    return ;
  if ((this->msg = strdup(msg)) == NULL)
    return ;
}
