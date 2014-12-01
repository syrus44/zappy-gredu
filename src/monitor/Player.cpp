//
// Player.cpp for  in /home/petit_p//projets/Zappy/local
// 
// Made by pierre petit
// Login   <petit_p@epitech.net>
// 
// Started on  Mon Jun 24 13:46:09 2013 pierre petit
// Last update Fri Jul 12 01:45:50 2013 louis cailleux
//

#include "Player.hh"
#include <irrlicht.h>

Player::Player(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *scene,
	       irr::IrrlichtDevice * d, int const &id, int const &x, int const &y, int const &dir)
{
  this->_driver = driver;
  this->_scene = scene;
  this->_name = "Player";
  this->_r = AObjects::Player;
  this->_id = id;
  this->lvl = 1;
  this->posX = x;
  this->posY = y;
  this->posZ = 500;
  this->_dir = dir;
  this->t = new Text(scene, d);
}

Player::~Player()
{}

void	Player::createObject()
{
  this->_mesh = this->_scene->getMesh("asset/models/player.md2");
  if (!this->_mesh)
    throw Exception("Unable to load player ture MD2.");
  this->_node = this->_scene->addAnimatedMeshSceneNode(this->_mesh);
}

void	Player::blitTexture()
{

  this->_node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  this->_node->setScale(irr::core::vector3df(3, 3, 3));
  this->_node->setPosition(irr::core::vector3df((this->posX + 1) * 100, 215, (this->posY + 1) * 100));
  this->Direction();
  this->_node->setMD2Animation(irr::scene::EMAT_RUN);
  this->_node->setMaterialTexture(0, this->_driver->getTexture("asset/models/player.bmp"));
}

void	Player::Direction()
{
  switch (this->_dir)
    {
    case 1:
      this->_node->setRotation(irr::core::vector3df(0, 90,0));
      break;
    case 2:
      this->_node->setRotation(irr::core::vector3df(0, -90,0));
      break;
    case 3:
      this->_node->setRotation(irr::core::vector3df(0, 180,0));
      break;
    case 4:
      this->_node->setRotation(irr::core::vector3df(0, -180,0));
      break;
    default: break;
    }
}

void	Player::destroyObject()
{
  this->_node->remove();
}

const std::string & Player::getName() const
{
  return (this->_name);
}

int	Player::getPosX() const
{
  return (this->posX);
}

int	Player::getPosY() const
{
  return (this->posY);
}

int	Player::getPosZ() const
{
  return (this->posZ);
}

int	Player::getId() const
{
  return (this->_id);
}

void	Player::setPosX(int const &x)
{
  this->posX = x;
}

void	Player::setPosY(int const &y)
{
  this->posY = y;
}

void	Player::setPosZ(int const &z)
{
  this->posZ = z;
}

void	Player::setDir(int dir)
{
  this->_dir = dir;
}

AObjects::Ressource const & Player::getRessource() const
{
  return (this->_r);
}

void	Player::setLvl(int l)
{
  this->lvl = l;
  this->t->levelUp(this->posX, this->posY);
  this->t->setDisplayed(true);
}

void	Player::displayLevel()
{
  std::string		player("Player: ");
  std::stringstream	iss;
  
  iss << this->_id << " lvl: " << this->lvl;
  player += iss.str();
  this->t->affText(player, irr::core::dimension2d< irr::f32 >(125.0f, 50.0f), irr::core::vector3df((this->posX + 1) * 100, 325, (this->posY + 1) * 100), irr::video::SColor(100, 255, 255, 255));
  iss.clear();
}

void	Player::removeStr()
{
  this->t->removeStr();
  if (this->t->isDisplayed() == true)
    {
      this->t->remove();
      this->t->setDisplayed(false);
    }
}

int	Player::getLvl() const
{
  return (this->lvl);
}
