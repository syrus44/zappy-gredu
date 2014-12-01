//
// Thystame.cpp for Thystame in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:01:42 2013 jordan bettin
// Last update Fri Jul 12 01:36:27 2013 louis cailleux
//

#include "Thystame.hh"

Thystame::Thystame(irr::video::IVideoDriver *d, irr::scene::ISceneManager *s, int  const & x, int const & y, int const & z) : ASphere(d, s, x, y, z)
{
  this->lvl = 0;
  this->drv = d;
  this->scn = s;
  this->_id = 0;
  this->name = "Thystame";
  this->_r = AObjects::Thystame;
  this->posX = x;
  this->posY = y;
  this->posZ = z;
}

Thystame::~Thystame()
{}

void	Thystame::createObject()
{
  this->node = this->scn->addSphereSceneNode(20);
  this->node->setPosition(irr::core::vector3df(posX, posY, posZ));
}

void	Thystame::blitTexture()
{
  this->node->setMaterialTexture(0, this->drv->getTexture(THYSTAME));
  this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

int	Thystame::getPosX() const
{
  return (this->posX);
}

int	Thystame::getPosY() const
{
  return (this->posY);
}

int	Thystame::getPosZ() const
{
  return (this->posZ);
}

void	Thystame::setPosX(int const & x)
{
  this->posX = x;
}

void	Thystame::setPosY(int const & y)
{
  this->posY = y;
}

void	Thystame::setPosZ(int const & z)
{
  this->posZ = z;
}

int	Thystame::getId() const
{
  return (this->_id);
}

void	Thystame::destroyObject()
{
  this->node->remove();
}

AObjects::Ressource const & Thystame::getRessource() const
{
  return (this->_r);
}

const std::string &	Thystame::getName() const
{
  return (this->name);
}

void	Thystame::setDir(int d)
{
  ++d;
}

void	Thystame::setLvl(int l)
{
  ++l;
}

int	Thystame::getLvl() const
{
  return (this->lvl);
}

void	Thystame::displayLevel()
{}

void	Thystame::removeStr()
{}

