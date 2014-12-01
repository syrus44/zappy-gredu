/*
** objects.h for  in /home/petit_p//projets/Zappy/zappy-gredu/trunk/sparw
** 
** Made by pierre petit
** Login   <petit_p@epitech.net>
** 
** Started on  Tue Apr 30 14:24:20 2013 pierre petit
** Last update Sat Jul 13 17:49:59 2013 jimmy farcy
*/

#ifndef	 _OBJECTS_H_
# define _OBJECTS_H_

# include <stddef.h>
# include <stdlib.h>

typedef enum		e_ressources
  {
    Food,
    Linemate,
    Deraumere,
    Sibur,
    Mendiane,
    Phiras,
    Thystame,
    Player
  }			resource;

typedef struct		s_objects
{
  int			x;
  int			y;
  resource		id;

  int			(*getX)(struct s_objects *);
  int			(*getY)(struct s_objects *);
  resource		(*getobject)(struct s_objects *);
  void			(*setX)(struct s_objects *, int );
  void			(*setY)(struct s_objects *, int );
  void			(*setobject)(struct s_objects *, resource );
}			t_objects;

int			initObject(t_objects *);
void			destroyObject(t_objects *);
void			*xmalloc(size_t );

#endif	/*OBJECTS*/
