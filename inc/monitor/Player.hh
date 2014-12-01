//
// Player.cpp for  in /home/petit_p//projets/Zappy/local
// 
// Made by pierre petit
// Login   <petit_p@epitech.net>
// 
// Started on  Mon Jun 24 13:43:58 2013 pierre petit
// Last update Fri Jul 12 01:45:26 2013 louis cailleux
//

#ifndef	PLAYER_HH
#define	PLAYER_HH

#include <irrlicht.h>
#include <iostream>

#include "AObjects.hh"
#include "Exception.hh"
#include "Text.hh"

class	Player: public AObjects
{
private:
  irr::scene::IAnimatedMesh		*_mesh;
  irr::scene::ISceneManager		*_scene;
  irr::video::IVideoDriver		*_driver;
  irr::scene::IAnimatedMeshSceneNode	*_node;
  std::string				_name;
  int					_id;
  int					_posX;
  int					_posY;
  int					_dir;
  Ressource				_r;
  Text					*t;

public:
  Player(irr::video::IVideoDriver *, irr::scene::ISceneManager *,
	 irr::IrrlichtDevice *, int const &, int const &, int const &, int const &);
  ~Player();

public:
  virtual void					createObject();
  virtual void					Direction();
  virtual void					blitTexture();
  virtual void					destroyObject();
  virtual int					getPosX() const;
  virtual int					getPosY() const;
  virtual int					getPosZ() const;
  virtual int					getId() const;
  virtual const std::string &			getName() const;
  virtual AObjects::Ressource const &		getRessource() const;
  virtual void					setPosX(int const &);
  virtual void					setPosY(int const &);
  virtual void					setPosZ(int const &);
  virtual void					setDir(int);
  virtual int					getLvl() const;
  virtual void					setLvl(int);
  virtual void					displayLevel();
  virtual void					removeStr();
};

#endif /*PLAYER_HH*/
