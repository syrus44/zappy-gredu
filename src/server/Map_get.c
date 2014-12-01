/*
** Map_get.c for zappy in /home/caille_l//Documents/sparw/src
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Tue May  7 16:44:48 2013 louis cailleux
** Last update Tue May  7 18:06:45 2013 louis cailleux
*/

#include "map.h"

extern int	getSizeX(t_map *this);
extern int	getSizeY(t_map *this);
extern int	getMaxX(t_map *this);
extern int	getMaxY(t_map *this);

extern int	getSizeX(t_map *this)
{
  if (!this)
    return (-1);
  return (this->x);
}

extern int	getSizeY(t_map *this)
{
 if (!this)
    return (-1);
  return (this->y);
}

extern int	getMaxX(t_map *this)
{
 if (!this)
    return (-1);
  return (this->max_x);
}

extern int	getMaxY(t_map *this)
{
 if (!this)
    return (-1);
  return (this->max_y);
}
