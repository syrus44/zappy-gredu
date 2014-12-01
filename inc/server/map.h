/*
** map.h for  in /home/petit_p//projets/Zappy/zappy-gredu/trunk/sparw
** 
** Made by pierre petit
** Login   <petit_p@epitech.net>
** 
** Started on  Tue Apr 30 15:12:44 2013 pierre petit
** Last update Wed Jul 10 01:14:13 2013 louis cailleux
*/

#ifndef	 _MAP_H_
# define _MAP_H_

#include <stdio.h>
#include <time.h>
#include "objects.h"

typedef struct s_qt
{
  int          f;
  int          l;
  int          d;
  int          s;
  int          m;
  int          p;
  int          t;
}              t_qt;

typedef struct		s_map
{
  int		        max_x;
  int			max_y;
  int			x;
  int			y;
  int			***map;
  char			*serial;
  t_objects		*o;
  int			(*getSizeX)(struct s_map *);
  int			(*getSizeY)(struct s_map *);
  int			(*getMaxY)(struct s_map *);
  int			(*getMaxX)(struct s_map *);
  void			(*setSizeX)(struct s_map *, int);
  void			(*setSizeY)(struct s_map *, int);
  void			(*setMaxY)(struct s_map *, int);
  void			(*setMaxX)(struct s_map *, int);
  void			(*initFct)(struct s_map *);
  int			(*createMap)(struct s_map *, int, int, int);
  void			(*showMap)(struct s_map *);
  void			(*destructMap)(struct s_map *);
  void			(*addRessources)(struct s_map *);
  int			(*serialize)(struct s_map *);
  int			(*Mapinit)(struct s_map *);
}                       t_map;

void			initMap(t_map *, int, int);
void			destroyMap(t_map *);
char                    *quantity(int *);
void                    init_qt(t_qt *);
void			set_quantity(t_qt *, int);

#endif /*_MAP_H_*/
