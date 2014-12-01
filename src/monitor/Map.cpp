//
// Landscape.cpp for Map in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:16:20 2013 jordan bettin
// Last update Sun Jul 14 16:56:46 2013 pierre petit
//

#include "Map.hh"

Map::Map(int const &x, int const &y, int const & fd)
{
  this->nbFPS = 0;
  this->mapX = 0;
  this->mapY = 0;
  this->_fd = fd;
  this->setMapX(x);
  this->setMapY(y);
  this->initEverything();
}

Map::~Map()
{}

void	Map::initEverything()
{
  this->initDriver();
  this->initScene();
  this->initMap();
  this->initRessources();
  this->createSkybox();
}

void	Map::initDriver()
{
  this->device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(1280, 1024), 16, false, false, true, 0);
  if (!(this->device))
    throw Exception("Invalid driver ! STOP !");
  this->driver = this->device->getVideoDriver();
  this->smgr = this->device->getSceneManager();
  this->device->setEventReceiver(&this->e);
}

void	Map::initScene(void)
{
  this->driver->setTextureCreationFlag(irr::video::ETCF_ALWAYS_16_BIT, true);
  this->camera = this->smgr->addCameraSceneNodeFPS(0, 100.0f, 1.2f);
  this->camera->setPosition(irr::core::vector3df(600*2, 300*2, 600*2));
  this->camera->setTarget(irr::core::vector3df(100, 0, 60));
  this->camera->setFarValue(42000.0f);
  this->device->getCursorControl()->setVisible(false);
}

void	Map::initMap()
{
  int	x = 0;
  int	y = 0;
  int	fx = 100;
  int	fy = 100;

  while (x != this->mapX)
    {
      y = 0;
      fy = 100;
      while (y != this->mapY)
	{
	  this->_floor = new Cube(this->driver, this->smgr, fx, 100, fy);
	  this->_floor->createObject();
	  this->_floor->blitTexture();
	  fy += 100;
	  y++;
	  this->_floor->setPosZ(fy);
	}
      fx += 100;
      x++;
      this->_floor->setPosX(fx);
    }
}

void	Map::initRessources(void)
{
  std::map<int, std::map<int, std::vector<AObjects*> > >::iterator	itX;
  std::map<int, std::vector<AObjects*> >::iterator			itY;
  std::vector<AObjects*>::iterator					itR;
  int	x = 100;
  int	y = 100;
  int	height = 160;

  for (itX = this->ground.begin(); itX != this->ground.end(); itX++)
    {
      y = 100;
      for (itY = itX->second.begin(); itY != itX->second.end(); itY++)
	{
	  for (itR = itY->second.begin(); itR != itY->second.end(); itR++)
	    {
	      if ((*itR)->getName() != "Grass")
		{
		  (*itR)->setPosX(x);
		  (*itR)->setPosZ(y);
		  (*itR)->setPosY(height);
		  (*itR)->createObject();
		  (*itR)->blitTexture();
		  height += 30;
		}
	    }
	  height = 160;
	  y += 100;
	}
      x += 100;
    }
}

void	Map::createSkybox(void)
{
  this->driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
  this->skybox = this->smgr->addSkyBoxSceneNode(this->driver->getTexture(UP),
						this->driver->getTexture(DOWN),
						this->driver->getTexture(LEFT),
						this->driver->getTexture(RIGHT),
						this->driver->getTexture(FRONT),
						this->driver->getTexture(BACK));
  this->driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
}

void	Map::printFPS(void)
{
  irr::core::stringw	str = L"Zappy Gredu - Irrlicht 1.8 Engine";

  str += this->driver->getName();
  str += "] FPS : ";
  str += this->getFPS();

  this->device->setWindowCaption(str.c_str());
}

void	Map::drawAllMembers(void)
{
  int	lastFPS = -1;

  this->device->run();
  this->driver->beginScene(true, true, 0);
  this->smgr->drawAll();
  this->driver->endScene();
  this->setFPS(this->driver->getFPS());
  if (lastFPS != this->getFPS())
    {
      this->printFPS();
      this->setFPS(lastFPS);
    }
  if (this->e.IsKeyDown(irr::KEY_ESCAPE) || this->e.IsKeyDown(irr::KEY_LMENU))
    {
      close(this->_fd);
      this->device->closeDevice();
      this->device->drop();
      throw Exception("Closing monitor");
    }
}

void	Map::setMapX(int const &x)
{
  this->mapX = x;
}

void	Map::setMapY(int const &y)
{
  this->mapY = y;
}

int	Map::getMapX() const
{
  return (this->mapX);
}

int	Map::getMapY() const
{
  return (this->mapY);
}

void	Map::setFPS(int const &f)
{
  this->nbFPS = f;
}

int	Map::getFPS() const
{
  return (this->nbFPS);
}

irr::video::IVideoDriver *Map::getDriver() const
{
  return (this->driver);
}

irr::scene::ISceneManager *Map::getScene() const
{
  return (this->smgr);
}

irr::IrrlichtDevice*	Map::getDevice() const
{
  return (this->device);
}

void	Map::setMap(std::map<int, std::map<int, std::vector<AObjects *> > > const &m)
{
  this->ground = m;
}
