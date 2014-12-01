//
// AObjects.hh for AObjects in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 09:40:37 2013 jordan bettin
// Last update Fri Jul 12 01:42:12 2013 louis cailleux
//

#ifndef AOBJECTS_HH
#define AOBJECTS_HH

#include "Exception.hh"
#include <irrlicht.h>
#include <iostream>
#include <string>

#define	GRASS		"./asset/ressources/grass.jpg"
#define FOOD		"./asset/ressources/food.jpg"
#define DERAUMERE	"./asset/ressources/deraumere.png"
#define THYSTAME	"./asset/ressources/thystame.jpg"
#define SIBUR		"./asset/ressources/sibur.jpg"
#define LINEMATE	"./asset/ressources/linemate.jpg"
#define PHIRAS		"./asset/ressources/phiras.jpg"
#define MENDIANE	"./asset/ressources/mendiane.jpg"

class	AObjects
{
public:
  typedef enum		e_ressources
  {
    Food = 0,
    Linemate = 1,
    Deraumere = 2,
    Sibur = 3,
    Mendiane = 4,
    Phiras = 5,
    Thystame = 6,
    Grass = 7,
    Player = 8,
  }			Ressource;
  AObjects();
  ~AObjects();
  virtual void	createObject() = 0;
  virtual void	blitTexture() = 0;
  virtual void	setPosX(int const &) = 0;
  virtual void	setPosY(int const &) = 0;
  virtual void	setPosZ(int const &) = 0;
  virtual void	setLvl(int) = 0;
  virtual int	getPosX() const = 0;
  virtual int	getPosY() const = 0;
  virtual int	getPosZ() const = 0;
  virtual int	getId() const = 0;
  virtual int   getLvl() const = 0;
  virtual void	destroyObject() = 0;
  virtual const std::string & getName() const = 0;
  virtual void	setDir(int) = 0;
  virtual void  removeStr() = 0;
  virtual void  displayLevel() = 0;
  virtual Ressource const & getRessource() const = 0;

protected:
  irr::video::IVideoDriver	*drv;
  irr::scene::ISceneManager	*scn;
  irr::scene::ISceneNode	*node;
  irr::scene::ISceneNodeAnimator *anim;
  std::string name;
  int	posX;
  int	posY;
  int	posZ;
  int	_id;
  int	lvl;
  Ressource _r;
};

#endif
