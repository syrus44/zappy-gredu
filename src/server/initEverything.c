/*
** loop.c for initEverything in /home/bettin_j//SVN/zappy-gredu/branches/ZappySockets
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Fri May 10 10:59:42 2013 jordan bettin
** Last update Thu Jul 11 18:34:42 2013 louis cailleux
*/

#include	"server.h"

int		initEverything(t_server *srv, t_argument *args)
{
  t_objects	*obj;
  t_map		*map;

  if ((obj = malloc(sizeof(t_objects))) == NULL)
    return (-1);
  if (initObject(obj) == -1)
    return (-1);
  if ((map = malloc(sizeof(t_map))) == NULL)
    return (-1);
  initMap(map, args->width, args->height);
  map->Mapinit(map);
  map->serialize(map);
  srv->objects = obj;
  srv->map = map;
  srv->id = 1;
  srv->fd_grap = -1;
  srv->grap_set = 0;
  return (0);
}
