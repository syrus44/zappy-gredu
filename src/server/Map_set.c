/*
** Map_set.c for zappy in /home/caille_l//Documents/sparw/src
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Tue May  7 16:45:06 2013 louis cailleux
** Last update Wed Jul 10 00:43:43 2013 louis cailleux
*/

#include "map.h"

extern void	setSizeX(t_map *this, int x);
extern void	setSizeY(t_map *this, int y);
extern void	setMaxX(t_map *this, int x);
extern void	setMaxY(t_map *this, int y);
extern void	destructMap(t_map *this);

extern void	destructMap(t_map *this)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < this->max_x)
    {
      while (j < this->max_y)
	{
	  free(this->map[i][j]);
	  ++j;
	}
      j = 0;
      free(this->map[i]);
      ++i;
    }
  free(this->map);
}

extern void	setSizeX(t_map *this, int x)
{
  if (!this)
    return ;
  this->x = x;
}

extern void	setSizeY(t_map *this, int y)
{
  if (!this)
    return ;
  this->y = y;
}

extern void	setMaxX(t_map *this, int x)
{
  if (!this)
    {
      printf("fail");
      return ;
    }
  this->max_x = x;
}

extern void	setMaxY(t_map *this, int y)
{
  if (!this)
    return ;
  this->max_y = y;
}
