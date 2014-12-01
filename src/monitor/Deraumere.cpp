//
// Deraumere.cpp for Deraumere in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:00:24 2013 jordan bettin
// Last update Fri Jul 12 01:42:35 2013 louis cailleux
//

#include "Deraumere.hh"

Deraumere::Deraumere(irr::video::IVideoDriver *d, irr::scene::ISceneManager *s, int const &x, int const &y, int const &z) : ASphere(d, s, x, y, z)
{
  this->drv = d;
  this->scn = s;
  this->name = "Deraumere";
  this->_r = AObjects::Deraumere;
  this->_id = 0;
  this->lvl = 0;
  this->posX = x;
  this->posY = y;
  this->posZ = z;
}

Deraumere::~Deraumere()
{}

void	Deraumere::createObject()
{
  this->node = this->scn->addSphereSceneNode(20);
  this->node->setPosition(irr::core::vector3df(posX, posY, posZ));
}

void	Deraumere::blitTexture()
{
  this->node->setMaterialTexture(0, this->drv->getTexture(DERAUMERE));
  this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

int	Deraumere::getPosX() const
{
  return (this->posX);
}

int	Deraumere::getPosY() const
{
  return (this->posY);
}

int	Deraumere::getPosZ() const
{
  return (this->posZ);
}

void	Deraumere::setPosX(int const &x)
{
  this->posX = x;
}

void	Deraumere::setPosY(int const &y)
{
  this->posY = y;
}

void	Deraumere::setPosZ(int const &z)
{
  this->posZ = z;
}

void	Deraumere::destroyObject()
{
  this->node->remove();
}

const std::string &	Deraumere::getName() const
{
  return (this->name);
}

int	Deraumere::getId() const
{
  return (this->_id);
}

void	Deraumere::setDir(int d)
{
  ++d;
}

AObjects::Ressource const & Deraumere::getRessource() const
{
  return (this->_r);
}

void	Deraumere::setLvl(int l)
{
  ++l;
}

int	Deraumere::getLvl() const
{
  return (this->lvl);
}

void	Deraumere::displayLevel()
{}

void	Deraumere::removeStr()
{}
