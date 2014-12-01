//
// ParsCom.hh for Zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Sat Jun 29 13:39:50 2013 louis cailleux
// Last update Fri Jul 12 00:10:47 2013 louis cailleux
//

#ifndef PARSCOM_HH
#define PARSCOM_HH

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include "Network.hh"
#include "mapIA.hh"

class	ParsCom
{
  mapIA		*_create;
  Network	*_net;
  Talk		*_talk;
  std::vector<std::string>	_listTeam;
  std::vector<int>		_listPlayer;
  std::map<std::string, void (ParsCom::*)()>	ptrFunc;
  std::string	_arg;
  std::string	_exstr;
  std::string	_parameters;
  std::string	_paramStr;

public:
  ParsCom(mapIA *, Network *, Talk *);
  ~ParsCom();

  const std::string &	getArg() const;
  void			extractString(std::string);
  void			extractNumber();
  void			extractParamStr();
  void			Pars(std::string &);
  void			countSpace(int) const;
  int			convert(std::string const &) const;
  void			getMapSize();
  void			getAllMap();
  void			invalidParam() const;
  void			endTime();
  void			lookTeam();
};

#endif
