/*
** Map.c for zappy in /home/caille_l//Documents/objects
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Thu May  9 15:10:59 2013 louis cailleux
** Last update Sun Jul 14 19:15:52 2013 louis cailleux
*/

#include <unistd.h>
#include <stdlib.h>
#include "map.h"

extern int	getSizeX(t_map *this);
extern int	getSizeY(t_map *this);
extern int	getMaxX(t_map *this);
extern int	getMaxY(t_map *this);
extern void	setSizeX(t_map *this, int x);
extern void	setSizeY(t_map *this, int y);
extern void	setMaxX(t_map *this, int x);
extern void	setMaxY(t_map *this, int y);
extern void	destructMap(t_map *this);
static void	initFct(t_map *this);
static int	createMap(t_map *, int, int, int);
extern int	serialize(t_map *this);
extern void	showMap(t_map *this);
extern void	addRessources(t_map *this);
static int	Mapinit(t_map *);

void		initMap(t_map *this, int x, int y)
{
  this->max_x = x;
  this->max_y = y;
  this->x = 0;
  this->y = 0;
  this->o = 0;
  this->serial = 0;
  this->initFct = &initFct;
  this->initFct(this);
  this->createMap = &createMap;
}

void		destroyMap(t_map *this)
{
  this->destructMap(this);
  if (this->serial)
    free(this->serial);
  this->setSizeX = NULL;
  this->setSizeY = NULL;
  this->setMaxX = NULL;
  this->setMaxY = NULL;
  this->getSizeX = NULL;
  this->getSizeY = NULL;
  this->getMaxX = NULL;
  this->getMaxY = NULL;
  this->createMap = NULL;
  this->showMap = NULL;
  this->destructMap = NULL;
  this->addRessources = NULL;
  this->Mapinit = NULL;
  free(this);
}

static void	initFct(t_map *this)
{
  this->setSizeX = &setSizeX;
  this->setSizeY = &setSizeY;
  this->setMaxX = &setMaxX;
  this->setMaxY = &setMaxY;
  this->getSizeX = &getSizeX;
  this->getSizeY = &getSizeY;
  this->getMaxX = &getMaxX;
  this->getMaxY = &getMaxY;
  this->showMap = &showMap;
  this->destructMap = &destructMap;
  this->addRessources = &addRessources;
  this->serialize = &serialize;
  this->Mapinit = &Mapinit;
}

static int	Mapinit(t_map *this)
{
  if (this->createMap(this, 0, 0, 0) == -1)
    return (-1);
  this->addRessources(this);
  return (0);
}

static int	createMap(t_map *this, int i, int j, int k)
{
  if ((this->map = malloc(sizeof(int **) * (this->max_x))) == NULL)
    return (-1);
  while (i < this->max_x)
    {
      if ((this->map[i] = malloc(sizeof(int *) * this->max_y)) == NULL)
	return (-1);
      while (j < this->max_y)
	{
	  if ((this->map[i][j] = malloc(sizeof(int) * 5)) == NULL)
	    return (-1);
	  while (k < 5)
	    {
	      this->map[i][j][k] = 7;
	      ++k;
	    }
	  k = 0;
	  ++j;
	}
      j = 0;
      ++i;
    }
  return (0);
}
