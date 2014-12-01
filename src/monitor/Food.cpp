//
// Food.cpp for Food in /home/bettin_j//SVN/zappy-gredu/branches/Syrus
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Mon Jun 17 15:56:43 2013 jordan bettin
// Last update Fri Jul 12 01:43:16 2013 louis cailleux
//

#include	"Food.hh"

Food::Food(irr::video::IVideoDriver *d, irr::scene::ISceneManager *s, int const &x, int const &y, int const &z) : ASphere(d, s, x, y, z)
{
  this->drv = d;
  this->scn = s;
  this->_id = 0;
  this->lvl = 0;
  this->_r = AObjects::Food;
  this->name = "Food";
  this->posX = x;
  this->posY = y;
  this->posZ = z;
}

Food::~Food()
{}

void	Food::createObject()
{
  this->node = this->scn->addSphereSceneNode(20);
  this->node->setPosition(irr::core::vector3df(posX, posY, posZ));
}

void	Food::blitTexture()
{
  this->node->setMaterialTexture(0, this->drv->getTexture(FOOD));
  this->node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

int	Food::getPosX() const
{
  return (this->posX);
}

int	Food::getPosY() const
{
  return (this->posY);
}

int	Food::getPosZ() const
{
  return (this->posZ);
}

void	Food::setPosX(int const &x)
{
  this->posX = x;
}

void	Food::setPosY(int const &y)
{
  this->posY = y;
}

void	Food::setPosZ(int const &z)
{
  this->posZ = z;
}

int	Food::getId() const
{
  return (this->_id);
}

void	Food::destroyObject()
{
  this->node->remove();
}

const std::string &	Food::getName() const
{
  return (this->name);
}

void	Food::setDir(int d)
{
  ++d;
}

AObjects::Ressource const & Food::getRessource() const
{
  return (this->_r);
}

void	Food::setLvl(int l)
{
  ++l;
}

int	Food::getLvl() const
{
  return (this->lvl);
}

void	Food::displayLevel()
{}

void	Food::removeStr()
{}
