//
// Cube.hh for Cube in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 09:42:44 2013 jordan bettin
// Last update Fri Jul 12 01:41:48 2013 louis cailleux
//

#ifndef CUBE_HH
#define CUBE_HH

#include "AObjects.hh"
#include "Exception.hh"
#include <irrlicht.h>

class	Cube : public AObjects
{
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
  Ressource	_r;

public:
  Cube(irr::video::IVideoDriver *, irr::scene::ISceneManager *, int const &, int const &, int const &);
  ~Cube();
  virtual void	createObject();
  virtual void	destroyObject();
  virtual void	blitTexture();
  virtual void	setPosX(int const &);
  virtual void	setPosY(int const &);
  virtual void	setPosZ(int const &);
  virtual int	getPosX() const;
  virtual int	getPosY() const;
  virtual int	getPosZ() const;
  virtual int	getId() const;
  virtual void	setDir(int);
  virtual const std::string & getName() const;
  virtual AObjects::Ressource const & getRessource() const;
  virtual int   getLvl() const;
  virtual void	setLvl(int);
  virtual void  displayLevel();
  virtual void  removeStr();
};

#endif
