//
// Mendiane.cpp for Mendiane in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:03:28 2013 jordan bettin
// Last update Fri Jul 12 01:38:12 2013 louis cailleux
//

#include "Mendiane.hh"

Mendiane::Mendiane(irr::video::IVideoDriver *d, irr::scene::ISceneManager *s, int const &x, int const &y, int const &z) : ASphere(d, s, x, y, z)
{
  this->drv = d;
  this->scn = s;
  this->name = "Mendiane";
  this->_r = AObjects::Mendiane;
  this->_id = 0;
  this->lvl = 0;
  this->posX = x;
  this->posY = y;
  this->posZ = z;
}

Mendiane::~Mendiane()
{}

void	Mendiane::createObject()
{
  this->node = this->scn->addSphereSceneNode(20);
  this->node->setPosition(irr::core::vector3df(posX, posY, posZ));
}

void	Mendiane::blitTexture()
{
  this->node->setMaterialTexture(0, this->drv->getTexture(MENDIANE));
  this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

int	Mendiane::getPosX() const
{
  return (this->posX);
}

int	Mendiane::getPosY() const
{
  return (this->posY);
}

int	Mendiane::getPosZ() const
{
  return (this->posZ);
}

void	Mendiane::setPosX(int const &x)
{
  this->posX = x;
}

void	Mendiane::setPosY(int const &y)
{
  this->posY = y;
}

void	Mendiane::setPosZ(int const &z)
{
  this->posZ = z;
}

int	Mendiane::getId() const
{
  return (this->_id);
}

void	Mendiane::destroyObject()
{
  this->node->remove();
}

const std::string &	Mendiane::getName() const
{
  return (this->name);
}

void	Mendiane::setDir(int d)
{
  ++d;
}

AObjects::Ressource const & Mendiane::getRessource() const
{
  return (this->_r);
}

void	Mendiane::setLvl(int l)
{
  ++l;
}

int	Mendiane::getLvl() const
{
  return (this->lvl);
}

void	Mendiane::displayLevel()
{}

void	Mendiane::removeStr()
{}
