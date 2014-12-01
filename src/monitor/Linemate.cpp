//
// Linemate.cpp for Linemate in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:04:59 2013 jordan bettin
// Last update Fri Jul 12 01:39:41 2013 louis cailleux
//

#include "Linemate.hh"

Linemate::Linemate(irr::video::IVideoDriver *d, irr::scene::ISceneManager *s, int const &x, int const &y, int const &z) : ASphere(d, s, x, y, z)
{
  this->drv = d;
  this->scn = s;
  this->_r = AObjects::Linemate;
  this->name = "Linemate";
  this->_id = 0;
  this->lvl = 0;
  this->posX = x;
  this->posY = y;
  this->posZ = z;
}

Linemate::~Linemate()
{}

void	Linemate::createObject()
{
  this->node = this->scn->addSphereSceneNode(20);
  this->node->setPosition(irr::core::vector3df(posX, posY, posZ));
}

void	Linemate::blitTexture()
{
  this->node->setMaterialTexture(0, this->drv->getTexture(LINEMATE));
  this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

int	Linemate::getPosX() const
{
  return (this->posX);
}

int	Linemate::getPosY() const
{
  return (this->posY);
}

int	Linemate::getPosZ() const
{
  return (this->posZ);
}

void	Linemate::setPosX(int const &x)
{
  this->posX = x;
}

void	Linemate::setPosY(int const &y)
{
  this->posY = y;
}

void	Linemate::setPosZ(int const &z)
{
  this->posZ = z;
}

int	Linemate::getId() const
{
  return (this->_id);
}

void	Linemate::destroyObject()
{
  this->node->remove();
}

const std::string &	Linemate::getName() const
{
  return (this->name);
}

void	Linemate::setDir(int d)
{
  ++d;
}

AObjects::Ressource const & Linemate::getRessource() const
{
  return (this->_r);
}

void	Linemate::setLvl(int l)
{
  ++l;
}

int	Linemate::getLvl() const
{
  return (this->lvl);
}

void	Linemate::displayLevel()
{}

void	Linemate::removeStr()
{}
