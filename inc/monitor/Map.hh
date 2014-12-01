//
// Map.hh for Map in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:07:17 2013 jordan bettin
// Last update Sun Jul 14 14:56:13 2013 louis cailleux
//

#ifndef MAP_HH
#define MAP_HH

#include "Events.hh"
#include "Exception.hh"
#include "Cube.hh"
#include "Linemate.hh"
#include "Deraumere.hh"
#include "Phiras.hh"
#include "Thystame.hh"
#include "Sibur.hh"
#include "Mendiane.hh"
#include "Food.hh"

#include <irrlicht.h>
#include <sstream>
#include <iostream>
#include <ctime>
#include <map>
#include <vector>

#define	GRASS	"./asset/ressources/grass.jpg"
#define	UP	"./asset/skybox/space_up.png"
#define	DOWN	"./asset/skybox/space_dn.png"
#define	LEFT	"./asset/skybox/space_lf.png"
#define	RIGHT	"./asset/skybox/space_rt.png"
#define FRONT	"./asset/skybox/space_ft.png"
#define BACK	"./asset/skybox/space_bk.png"

class	Map
{
private:
  std::map<int, std::map<int, std::vector<AObjects *> > >	ground;
  irr::IrrlichtDevice		*device;
  irr::video::IVideoDriver	*driver;
  irr::scene::ISceneManager	*smgr;
  irr::scene::ICameraSceneNode	*camera;
  irr::scene::ISceneNode	*skybox;
  int				nbFPS;
  int				mapX;
  int				mapY;
  int				_fd;
  AObjects			*_floor;
  ASphere			*s1;
  Events			e;

public:
  Map(int const &, int const &, int const &);
  ~Map();
  void	initEverything();
  void	initDriver();
  void	initScene(void);
  void	initMap();
  void	initRessources(void);
  ASphere	*determineSphere(int const &, int const &, int const &) const;
  void	drawAllMembers(void);
  void	createSkybox(void);
  void	printFPS(void);
  int	getMapX() const;
  int	getMapY() const;
  void	setMapX(int const &);
  void	setMapY(int const &);
  void	setFPS(int const &);
  int	getFPS() const;
  irr::scene::ISceneManager *getScene() const;
  irr::video::IVideoDriver *getDriver() const;
  irr::IrrlichtDevice *getDevice() const;
  void  setMap(std::map<int, std::map<int, std::vector<AObjects *> > > const &);
};

#endif
