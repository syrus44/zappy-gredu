//
// ASphere.hh for ASphere in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:08:44 2013 jordan bettin
// Last update Fri Jul 12 01:33:46 2013 louis cailleux
//

#ifndef ASPHERE_HH
#define ASPHERE_HH

#include "AObjects.hh"
#include "Exception.hh"
#include <irrlicht.h>

class	ASphere : public AObjects
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

public:
  ASphere(irr::video::IVideoDriver *, irr::scene::ISceneManager *, int const &, int const &, int const &);
  ~ASphere();
  virtual void	createObject() = 0;
  virtual void	blitTexture() = 0;
  virtual void	setPosX(int const &) = 0;
  virtual void	setPosY(int const &) = 0;
  virtual void	setPosZ(int const &) = 0;
  virtual int	getPosX() const = 0;
  virtual int	getPosY() const = 0;
  virtual int	getPosZ() const = 0;
  virtual const std::string & getName() const = 0;
};

#endif
