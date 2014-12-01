/*
** objects.c for objects in /home/bettin_j//SVN/zappy-gredu/trunk/objects
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Wed May  8 13:13:18 2013 jordan bettin
** Last update Sun Jul 14 19:26:22 2013 louis cailleux
*/

#include "objects.h"

static int	getX(t_objects *this);
static int	getY(t_objects *this);
static void	setX(t_objects *this, int x);
static void	setY(t_objects *this, int y);
extern resource	getobject(t_objects *this);
extern void	setobject(t_objects *this, resource id);

int		initObject(t_objects *this)
{
  this->x = 0;
  this->y = 0;
  this->id = 0;
  this->setX = &setX;
  this->setY = &setY;
  this->setobject = &setobject;
  this->getX = &getX;
  this->getY = &getY;
  this->getobject = &getobject;
  return (0);
}

static int	getX(t_objects *this)
{
  if (this == NULL)
    return (-1);
  return (this->x);
}

static int	getY(t_objects *this)
{
  if (this == NULL)
    return (-1);
  return (this->y);
}

static void	setX(t_objects *this, int x)
{
  if (this == NULL)
    return ;
  this->x = x;
}

static void	setY(t_objects *this, int y)
{
  if (this == NULL)
    return ;
  this->y = y;
}
