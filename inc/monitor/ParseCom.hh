//
// ParseCom.hh for ParsCom in /home/charle_b//Desktop/System_unix/Zappy/parse_client
// 
// Made by mael charles
// Login   <charle_b@epitech.net>
// 
// Started on  Fri Jun 14 16:35:22 2013 mael charles
// Last update Fri Jul 12 01:48:46 2013 louis cailleux
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
#include "CreateMap.hh"

class	ParsCom
{
  CreateMap	*_create;
  Network	*_net;
  Talk		*_talk;
  std::vector<std::string>	_listTeam;
  std::vector<int>		_listPlayer;
  std::map<std::string, void (ParsCom::*)()>	ptrFunc;
  std::string	_arg;
  std::string	_exstr;
  std::string	_parameters;
  std::string	_paramStr;
  int		_x;
  int		_y;
  int		_q;
  int		_n;
  int		_O;
  int		_L;
  int		_e;
  int		_T;
  std::string  	_N;
  std::string  	_R;
  std::string  	_M;
  int		_i;
  int		_0;
  int		_1;
  int		_2;
  int		_3;
  int		_4;
  int		_5;
  int		_6;

public:
  ParsCom(CreateMap *, Network *, Talk *);
  ~ParsCom();

  const std::string &	getArg() const;
  void			extractString(std::string);
  void			extractNumber();
  void			extractParamStr();
  void			Pars(const std::string &);
  void			countSpace(int const &);
  int			convert(std::string const &);
  void			getMapSize();
  void			getAllMap();
  void			getIncantation();
  void			getNameTeam();
  void			getConnect();
  void			getPositionPlayer();
  void			getNiveau();
  void			getInventaire();
  void			getExpulse();
  void			getBroadcast();
  void			getEndIncantation();
  void			getPond();
  void			getThrowRes();
  void			getTakeRes();
  void			diePlayer();
  void			eggPondCase();
  void			eggBoum();
  void			connectEgg();
  void			dieEgg();
  void			getsetTime();
  void			endTime();
  void			getMessage();
  void			incCmd();
  void			invalidParam();
};

#endif
