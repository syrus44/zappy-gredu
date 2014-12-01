//
// Cube.cpp for Cube in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 09:49:28 2013 jordan bettin
// Last update Fri Jul 12 01:42:53 2013 louis cailleux
//

#include "Cube.hh"

Cube::Cube(irr::video::IVideoDriver *d, irr::scene::ISceneManager *s, int const &x, int const &y, int const &z)
{
  this->drv = d;
  this->scn = s;
  this->name = "Grass";
  this->_r = AObjects::Grass;
  this->posX = x;
  this->posY = y;
  this->_id = 0;
  this->lvl = 0;
  this->posZ = z;
}

Cube::~Cube()
{}

void	Cube::createObject()
{
  this->node = this->scn->addCubeSceneNode(100);
  this->node->setPosition(irr::core::vector3df(this->posX, this->posY, this->posZ));
}

void	Cube::blitTexture()
{
  this->node->setMaterialTexture(0, this->drv->getTexture(GRASS));
  this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

int	Cube::getPosX() const
{
  return (this->posX);
}

int	Cube::getPosY() const
{
  return (this->posY);
}

int	Cube::getPosZ() const
{
  return (this->posZ);
}

void	Cube::setPosX(int const &x)
{
  this->posX = x;
}

void	Cube::setPosY(int const &y)
{
  this->posY = y;
}

void	Cube::setPosZ(int const &z)
{
  this->posZ = z;
}

int	Cube::getId() const
{
  return (this->_id);
}

void	Cube::destroyObject()
{
  this->node->remove();
}

const std::string &	Cube::getName() const
{
  return (this->name);
}

void	Cube::setDir(int d)
{
  ++d;
}

AObjects::Ressource const & Cube::getRessource() const
{
  return (this->_r);
}

void	Cube::setLvl(int l)
{
  ++l;
}

int	Cube::getLvl() const
{
  return (this->lvl);
}

void	Cube::displayLevel()
{}

void	Cube::removeStr()
{}
