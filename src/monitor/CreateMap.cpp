//
// CreateMap.cpp for zappy in /home/caille_l//Documents/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Mon Jun 17 18:25:13 2013 louis cailleux
// Last update Sun Jul 14 17:15:12 2013 pierre petit
//

#include <iostream>
#include <string>
#include <algorithm>
#include "CreateMap.hh"
#include "Player.hh"
#include <cstdlib>

CreateMap::CreateMap(int const &fd)
{
  this->_sizeX = 0;
  this->_sizeY = 0;
  this->_fd = fd;
  this->_nbObj = 1;
  this->_isInit = false;
}

CreateMap::~CreateMap()
{}

void	CreateMap::setSize(std::string const & size)
{
  std::istringstream iss;
  int		     tmp = 4;
  int		     y = 0;
  
  for (std::string::const_iterator x = size.begin(); x != size.end(); ++x)
    {
      if (((*x) == ' ' || (*x) == '\n') && y > 4)
	{
	  iss.str(size.substr(tmp, (y - tmp)));
	  if (tmp == 4)
	    iss >> this->_sizeX;
	  else
	    iss >> this->_sizeY;
    	  tmp = y + 1;
	  iss.clear();
	}
      ++y;
    }
  this->_3dMap = new Map(this->_sizeX, this->_sizeY, this->_fd);
  this->driver = this->_3dMap->getDriver();
  this->smgr = this->_3dMap->getScene();
  this->device = this->_3dMap->getDevice();
}

void	CreateMap::findLocation(std::string const &str, char find)
{
  unsigned int            i = 0;
  int			  nb = 0;
  
  if (!this->_space.empty())
    this->_space.erase(this->_space.begin(), this->_space.end());
  while (i < str.size())
    {
      if (str[i] == find)
	{
	  this->_space.insert(std::make_pair(nb, i));
	  ++nb;
	}
      i++;
    }
}

void	CreateMap::setObjects(int const &obj, int const &nb)
{
  for (int i = 0; i < nb; ++i)
    {
      if (this->_nbObj <= 5)
	{
	  switch (obj)
	    {
	    case 2:
	    this->_box.push_back(new Food(this->driver, this->smgr, 100, 100, 100));
	      break;
	    case 3:
	      this->_box.push_back(new Linemate(this->driver, this->smgr, 100, 100, 100));
	      break;
	    case 4:
	      this->_box.push_back(new Deraumere(this->driver, this->smgr, 100, 100, 100));
	      break;
	    case 5:
	      this->_box.push_back(new Sibur(this->driver, this->smgr, 100, 100, 100));
	      break;
	    case 6:
	      this->_box.push_back(new Mendiane(this->driver, this->smgr, 100, 100, 100));
	      break;
	    case 7:
	      this->_box.push_back(new Phiras(this->driver, this->smgr, 100, 100, 100));
	      break;
	    case 8:
	      this->_box.push_back(new Thystame(this->driver, this->smgr, 100, 100, 100));
	      break;
	    }
	  this->_nbObj++;
	}
    }
}

void	CreateMap::parseMap(std::string const &box)
{
  std::istringstream	       nb;
  std::map<int, int>::iterator jt;
  int tmp = 0, boxX = 0, boxY = 0;

  this->findLocation(box, ' ');
  this->_nbObj = 1;
  if (!this->_box.empty())
    this->_box.erase(this->_box.begin(), this->_box.end());
  for (std::map<int, int>::iterator it = this->_space.begin(); it != this->_space.end(); ++it)
    {
      jt = it;
       --jt;
       nb.str(box.substr(it->second, (it->second - (jt->second - 1))));
       nb >> tmp;
       if (it->first > 1)
	 this->setObjects(it->first, tmp);
       if (it->first == 0)
	 boxX = tmp;
       if (it->first == 1)
	 boxY = tmp;
       nb.clear();
    }

  if (this->_nbObj < 5)
    while (this->_nbObj <= 5)
      {
	this->_box.push_back(new Cube(this->driver, this->smgr, 100, 100, 100));
	this->_nbObj++;
      }
  if (this->_map.find(boxX) != this->_map.end())
    {
      if (this->_map.find(boxX)->second.find(boxY) != this->_map.find(boxX)->second.end())
	this->_map.find(boxX)->second.find(boxY)->second = this->_box;
    }
  else
    {
      this->_tmp.insert(std::make_pair(boxY, this->_box));
      if (boxY == (this->_sizeY - 1))
	{
	  this->_map.insert(std::make_pair(boxX, this->_tmp));
	  if (!this->_tmp.empty())
	    this->_tmp.erase(this->_tmp.begin(), this->_tmp.end());
	}
    }
  if (boxY == (this->_sizeY - 1) && boxX == (this->_sizeX - 1))
    {
      this->_3dMap->setMap(this->_map);
      this->_3dMap->initRessources();
      this->_isInit = true;
    }
}

void		CreateMap::showMap()
{
  for (std::map<int, std::map<int, std::vector<AObjects *> > >::iterator it = this->_map.begin(); it != this->_map.end(); ++it)
    {
      for (std::map<int, std::vector<AObjects *> >::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
	{
	  std::cout << "coord x " << it->first << " coord y " << jt->first << std::endl;
	  for (std::vector<AObjects *>::iterator x = jt->second.begin(); x != jt->second.end(); ++x)
	    {
	      std::cout << (*x)->getName() << " ";
	      std::cout << std::endl;
	    }
	}
    }
}

void		CreateMap::reInit(AObjects *obj, int const &x, int const &y, int const &dir) const
{
  obj->setPosX(x);
  obj->setPosY(y);
  obj->setDir(dir);
  obj->createObject();
  obj->blitTexture();
}

bool	CreateMap::valid_map(int const &x, int const &y) const
{
  std::map<int, std::map<int, std::vector<AObjects *> > >::const_iterator	it;
   
  if ((it = this->_map.find(x)) != this->_map.end())
    return (true);
  if (it->second.find(y) != it->second.end())
    return (true);
  return (false);      
}

void		CreateMap::movePlayer(int const &id, int const &x, int const &y, int const &dir)
{
  int					oldx, oldy;
  std::map<int, AObjects *>::iterator	p;

  if (this->valid_map(x, y) == true)
    {
      if ((p = this->_players.find(id)) != this->_players.end())
	{
	  oldx = p->second->getPosX();
	  oldy = p->second->getPosY();
	  if (this->_map[oldx][oldy].back()->getRessource() == AObjects::Player)
	    {
	      this->_map[oldx][oldy].back()->destroyObject();
	      this->_map[x][y].back() = this->_map[oldx][oldy].back();
	      if (oldx != x && oldy != y)
		this->_map[oldx][oldy].back() = new Cube(this->driver, this->smgr, 100, 100, 100);	    p->second->removeStr();
	      p->second->setPosX(x);
	      p->second->setPosY(y);
	      p->second->displayLevel();
	      this->reInit(this->_map[x][y].back(), x, y, dir);
	    }
	}
      else
	{
	  this->_map[x][y].back() = new Player(this->driver, this->smgr, this->device, id, x, y, dir);
	  this->_map[x][y].back()->createObject();
	  this->_map[x][y].back()->blitTexture();
	  this->_players.insert(std::make_pair(id, this->_map[x][y].back()));
	  p = this->_players.find(id);
	  p->second->displayLevel();
	}
      this->redraw();
    }
}

void		CreateMap::pickRess(int const &id, int const &ress)
{
  std::map<int, AObjects *>::iterator jt;
  std::vector<AObjects *>::iterator it;
  int   height = 160;
  
  if ((jt = this->_players.find(id)) != this->_players.end())
    {
      int x = jt->second->getPosX();
      int y = jt->second->getPosY();
      for (it = this->_map[x][y].begin(); it != this->_map[x][y].end(); ++it)
        {
          if ((*it)->getRessource() != AObjects::Grass && (*it)->getRessource() != AObjects::Player)
            (*it)->destroyObject();
          if ((*it)->getRessource() == ress)
            (*it) = new Cube(this->driver, this->smgr, 100, 100, 100);
        }
      for (it = this->_map[x][y].begin(); it != this->_map[x][y].end(); ++it)
        if ((*it)->getRessource() != AObjects::Grass && (*it)->getRessource() != AObjects::Player)
          {
            (*it)->setPosY(height);
            (*it)->createObject();
            (*it)->blitTexture();
            height += 30;
          }
    }
}

void	CreateMap::lvlUp(int const &id, int const &lvl)
{
  std::map<int, AObjects *>::iterator	p;
  
  if ((p = this->_players.find(id)) != this->_players.end())
    p->second->setLvl(lvl);
}

std::map<int, std::map<int, std::vector<AObjects *> > > const & CreateMap::getMap() const
{
  return (this->_map);
}

bool    CreateMap::getIsInit() const
{
  return (this->_isInit);
}

Map     *CreateMap::get3dMap() const
{
  return (this->_3dMap);
}

bool	isPart(char c)
{
  std::string pattern("0123456789 \n");
  return (pattern.find(c) != std::string::npos);
}

void	CreateMap::redraw()
{
  this->_3dMap->setMap(this->_map);
  this->driver->beginScene(true, true, 0);
  this->smgr->drawAll();
  this->driver->endScene();
}

void	CreateMap::freeMap()
{
  for (std::map<int, std::map<int, std::vector<AObjects *> > >::iterator it = this->_map.begin(); it != this->_map.end(); ++it)
    for (std::map<int, std::vector<AObjects *> >::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
      for (std::vector<AObjects *>::iterator x = jt->second.begin(); x != jt->second.end(); ++x)
	delete ((*x));
}
