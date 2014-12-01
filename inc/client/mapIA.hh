//
// mapIA.hh for mapIA in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy/inc/IA
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Sat Jun 29 11:55:54 2013 louis cailleux
// Last update Fri Jul 12 00:22:09 2013 louis cailleux
//

#ifndef MAPIA_HH_
# define MAPIA_HH_

#include <vector>
#include <map>
#include "Ia.hh"

class	mapIA
{
  int	_sizeX;
  int	_sizeY;
  int	_nbObj;
  int	_fd;
  bool	_launched;
  IA	*_ai;
  std::map<int, std::vector<int> >			_tmp;
  std::map<int, std::map<int, std::vector<int> > >	_map;
  std::map<int, int>					_space;
  std::vector<int>					_box;
    
public:
  mapIA(int const &, bool const &);
  ~mapIA();
  void setSize(std::string const &);
  void parseMap(std::string const &);
  void showMap() const;
  void findLocation(std::string const &, char);
  std::map<int, std::map<int, std::vector<int> > > const & getMap() const;
  void setObjects(int const &, int const &);
  int  getSizeX() const;
  int  getSizeY() const;
  int  getFd() const;
};

bool	isPart(char c);

#endif
