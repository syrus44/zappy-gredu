//
// CreateMap.hh for Zappy in /home/caille_l//Documents/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Mon Jun 17 17:37:10 2013 louis cailleux
// Last update Sun Jul 14 17:14:50 2013 pierre petit
//

#ifndef CREATEMAP_HH_
# define CREATEMAP_HH_

#include <vector>
#include <map>
#include "Map.hh"
#include "AObjects.hh"

class	CreateMap
{
  int	_sizeX;
  int	_sizeY;
  int	_nbObj;
  int	_fd;
  bool	_isInit;
  Map	*_3dMap;
    
  irr::video::IVideoDriver	*driver;
  irr::scene::ISceneManager	*smgr;
  irr::IrrlichtDevice		*device;
  std::map<int, std::vector<AObjects *> >			_tmp;
  std::map<int, std::map<int, std::vector<AObjects *> > >	_map;
  std::map<int, int>						_space;
  std::vector<AObjects *>					_box;
  std::map<int, AObjects *>					_players;

public:
  CreateMap(int const &);
  ~CreateMap();
  void setSize(std::string const &);
  void parseMap(std::string const &);
  void setObjects(int const &, int const &);
  void showMap();
  void redraw();
  void reInit(AObjects *, int const &, int const &, int const &) const;
  void findLocation(std::string const &, char);
  void freeMap();
  void movePlayer(int const &, int const &, int const &, int const &);
  void pickRess(int const &, int const &);
  void lvlUp(int const &, int const &);
  std::map<int, std::map<int, std::vector<AObjects *> > > const & getMap() const;
  bool getIsInit() const;
  bool valid_map(int const &, int const &) const;
  Map *get3dMap() const;
};

bool	isPart(char c);

#endif
