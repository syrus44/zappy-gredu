/*
** players_get.c for players_get in /home/bettin_j//ZappyObjects/src
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Tue May  7 17:58:16 2013 jordan bettin
** Last update Tue May  7 17:59:32 2013 jordan bettin
*/

#include "players.h"

extern int	getposX(t_players *this);
extern int	getposY(t_players *this);
extern int	getlevel(t_players *this);

extern int	getposX(t_players *this)
{
  if (this == NULL)
    return (-1);
  return (this->pos_x);
}

extern int	getposY(t_players *this)
{
  if (this == NULL)
    return (-1);
  return (this->pos_y);
}

extern int	getlevel(t_players *this)
{
  if (this == NULL)
    return (-1);
  return (this->lvl);
}
