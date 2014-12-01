//
// Sibur.hh for Sibur in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 16:58:25 2013 jordan bettin
// Last update Fri Jul 12 01:37:31 2013 louis cailleux
//

#ifndef SIBUR_HH
#define SIBUR_HH

#include "ASphere.hh"
#include "Exception.hh"
#include <irrlicht.h>

class	Sibur : public ASphere
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
  Ressource r;

public:
  Sibur(irr::video::IVideoDriver *, irr::scene::ISceneManager *, int const &, int const &, int const &);
  ~Sibur();
  virtual void	createObject();
  virtual void  destroyObject();
  virtual void	blitTexture();
  virtual void	setPosX(int const &);
  virtual void	setPosY(int const &);
  virtual void	setPosZ(int const &);
  virtual int	getPosX() const;
  virtual int	getPosY() const;
  virtual int	getPosZ() const;
  virtual int	getId() const;
  virtual void  setDir(int);
  virtual AObjects::Ressource const & getRessource() const;
  virtual const std::string & getName() const;
  virtual int   getLvl() const;
  virtual void	setLvl(int);
  virtual void  displayLevel();
  virtual void  removeStr();
};

#endif
