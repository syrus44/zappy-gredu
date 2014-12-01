//
// Sibur.cpp for Sibur in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:02:40 2013 jordan bettin
// Last update Fri Jul 12 01:37:51 2013 louis cailleux
//

#include "Sibur.hh"

Sibur::Sibur(irr::video::IVideoDriver *d, irr::scene::ISceneManager *s, int const &x, int const &y, int const &z) : ASphere(d, s, x, y, z)
{
  this->drv = d;
  this->lvl = 0;
  this->scn = s;
  this->name = "Sibur";
  this->_r = AObjects::Sibur;
  this->_id = 0;
  this->posX = x;
  this->posY = y;
  this->posZ = z;
}

Sibur::~Sibur()
{}

void	Sibur::createObject()
{
  this->node = this->scn->addSphereSceneNode(20);
  this->node->setPosition(irr::core::vector3df(posX, posY, posZ));
}

void	Sibur::blitTexture()
{
  this->node->setMaterialTexture(0, this->drv->getTexture(SIBUR));
  this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

int	Sibur::getPosX() const
{
  return (this->posX);
}

int	Sibur::getPosY() const
{
  return (this->posY);
}

int	Sibur::getPosZ() const
{
  return (this->posZ);
}

void	Sibur::setPosX(int const &x)
{
  this->posX = x;
}

void	Sibur::setPosY(int const &y)
{
  this->posY = y;
}

void	Sibur::setPosZ(int const &z)
{
  this->posZ = z;
}

int	Sibur::getId() const
{
  return (this->_id);
}

void	Sibur::destroyObject()
{
  this->node->remove();
}

AObjects::Ressource const & Sibur::getRessource() const
{
  return (this->_r);
}

const std::string &	Sibur::getName() const
{
  return (this->name);
}

void	Sibur::setDir(int d)
{
  ++d;
}

void	Sibur::setLvl(int l)
{
  ++l;
}

int	Sibur::getLvl() const
{
  return (this->lvl);
}

void	Sibur::displayLevel()
{}

void	Sibur::removeStr()
{}
