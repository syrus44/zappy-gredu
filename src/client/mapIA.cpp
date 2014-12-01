//
// mapIA.cpp for zappy in /home/caille_l//Documents/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Mon Jun 17 18:25:13 2013 louis cailleux
// Last update Fri Jul 12 00:22:27 2013 louis cailleux
//

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include "mapIA.hh"
#include "Ia.hh"

mapIA::mapIA(int const &fd, bool const &isLaunched)
{
  this->_sizeX = 0;
  this->_sizeY = 0;
  this->_nbObj = 1;
  this->_fd = fd;
  this->_launched = isLaunched;
}

mapIA::~mapIA()
{}

void	mapIA::setSize(std::string const & size)
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
}

void	mapIA::findLocation(std::string const &str, char find)
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

void	mapIA::parseMap(std::string const &box)
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
  if (this->_nbObj < NBCASES)
    while (this->_nbObj <= NBCASES)
      {
	this->_box.push_back(7);
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
  if (boxX == (this->_sizeX - 1) && boxY == (this->_sizeY - 1) && this->_launched == false)
    {
      std::string str("");
      this->_ai = new IA(this->_sizeX, this->_sizeY, this->_fd, this->_map);
      this->_ai->launchIa();
      this->_launched = true;
    }
}

void	mapIA::setObjects(int const &obj, int const &nb)
{
  for (int i = 0; i < nb; ++i)
    {
      if (this->_nbObj <= NBCASES)
	{
	  switch (obj)
	    {
	    case 2:
	      this->_box.push_back(0);
	      break;
	    case 3:
	      this->_box.push_back(1);
	      break;
	    case 4:
	      this->_box.push_back(2);
	      break;
	    case 5:
	      this->_box.push_back(3);
	      break;
	    case 6:
	      this->_box.push_back(4);
	      break;
	    case 7:
	      this->_box.push_back(5);
	      break;
	    case 8:
	      this->_box.push_back(6);
	      break;
	    }
	  this->_nbObj++;
	}
    }
}

void		mapIA::showMap() const
{
  for (std::map<int, std::map<int, std::vector<int> > >::const_iterator it = this->_map.begin(); it != this->_map.end(); ++it)
    {
      for (std::map<int, std::vector<int> >::const_iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
	{
	  std::cout << "coord x " << it->first << " coord y " << jt->first << std::endl;
	  for (std::vector<int>::const_iterator x = jt->second.begin(); x != jt->second.end(); ++x)
	    {
	      std::cout << (*x) << " ";
	      std::cout << std::endl;
	    }
	}
    }
}

int		mapIA::getSizeX() const
{
  return (this->_sizeX);
}

int		mapIA::getSizeY() const
{
  return (this->_sizeY);
}

int		mapIA::getFd() const
{
  return (this->_fd);
}

std::map<int, std::map<int, std::vector<int> > > const & mapIA::getMap() const
{
  return (this->_map);
}

bool	isPart(char c)
{
  std::string pattern("0123456789 \n");
  return (pattern.find(c) != std::string::npos);
}
