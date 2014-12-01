//
// Phiras.cpp for Phiras in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:04:23 2013 jordan bettin
// Last update Fri Jul 12 01:39:23 2013 louis cailleux
//

#include "Phiras.hh"

Phiras::Phiras(irr::video::IVideoDriver *d, irr::scene::ISceneManager *s, int const &x, int const &y, int const &z) : ASphere(d, s, x, y, z)
{
  this->drv = d;
  this->scn = s;
  this->_r = AObjects::Phiras;
  this->name = "Phiras";
  this->_id = 0;
  this->lvl = 0;
  this->posX = x;
  this->posY = y;
  this->posZ = z;
}

Phiras::~Phiras()
{}

void	Phiras::createObject()
{
  this->node = this->scn->addSphereSceneNode(20);
  this->node->setPosition(irr::core::vector3df(posX, posY, posZ));
}

void	Phiras::blitTexture()
{
  this->node->setMaterialTexture(0, this->drv->getTexture(PHIRAS));
  this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

int	Phiras::getPosX() const
{
  return (this->posX);
}

int	Phiras::getPosY() const
{
  return (this->posY);
}

int	Phiras::getPosZ() const
{
  return (this->posZ);
}

void	Phiras::setPosX(int const &x)
{
  this->posX = x;
}

void	Phiras::setPosY(int const &y)
{
  this->posY = y;
}

void	Phiras::setPosZ(int const &z)
{
  this->posZ = z;
}

int	Phiras::getId() const
{
  return (this->_id);
}

void	Phiras::destroyObject()
{
  this->node->remove();
}

const std::string &	Phiras::getName() const
{
  return (this->name);
}

void	Phiras::setDir(int d)
{
  ++d;
}

AObjects::Ressource const & Phiras::getRessource() const
{
  return (this->_r);
}

void	Phiras::setLvl(int l)
{
  ++l;
}

int	Phiras::getLvl() const
{
  return (this->lvl);
}

void	Phiras::displayLevel()
{}

void	Phiras::removeStr()
{}
