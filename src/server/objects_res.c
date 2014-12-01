/*
** objects2.c for objects in /home/bettin_j//SVN/zappy-gredu/trunk/objects
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Wed May  8 13:22:59 2013 jordan bettin
** Last update Wed May  8 13:32:37 2013 jordan bettin
*/

#include "objects.h"

extern void	setobject(t_objects *this, resource id);
extern resource	getobject(t_objects *this);

extern void	setobject(t_objects *this, resource id)
{
  if (this == NULL)
    return ;
  this->id = id;
}

extern resource	getobject(t_objects *this)
{
  if (this == NULL)
    return (-1);
  return (this->id);
}

