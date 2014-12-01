//
// ParseCom.cpp for ParsCom in /home/charle_b//Desktop/System_unix/Zappy/parse_client
// 
// Made by mael charles
// Login   <charle_b@epitech.net>
// 
// Started on  Fri Jun 14 16:33:33 2013 mael charles
// Last update Fri Jul 12 01:47:14 2013 louis cailleux
//

#include "ParseCom.hh"

ParsCom::ParsCom(CreateMap *create, Network *net, Talk *talk)
{
  this->_create = create;
  this->_net = net;
  this->_talk = talk;
  this->_arg = "";
  this->_exstr = "";
  this->_parameters = "";
  this->_paramStr = "";
  this->_x = -1;
  this->_y = -1;
  this->_q = -1;
  this->_n = -1;
  this->_O = -1;
  this->_L = -1;
  this->_e = -1;
  this->_0 = -1;
  this->_1 = -1;
  this->_2 = -1;
  this->_3 = -1;
  this->_4 = -1;
  this->_5 = -1;
  this->_6 = -1;
  this->ptrFunc["msz"] = &ParsCom::getMapSize;
  this->ptrFunc["bct"] = &ParsCom::getAllMap;
  this->ptrFunc["tna"] = &ParsCom::getNameTeam;
  this->ptrFunc["pnw"] = &ParsCom::getConnect;
  this->ptrFunc["ppo"] = &ParsCom::getPositionPlayer;
  this->ptrFunc["plv"] = &ParsCom::getNiveau;
  this->ptrFunc["pin"] = &ParsCom::getInventaire;
  this->ptrFunc["pex"] = &ParsCom::getExpulse;
  this->ptrFunc["pbc"] = &ParsCom::getBroadcast;
  this->ptrFunc["pic"] = &ParsCom::getIncantation;
  this->ptrFunc["pie"] = &ParsCom::getEndIncantation;
  this->ptrFunc["pfk"] = &ParsCom::getPond;
  this->ptrFunc["pdr"] = &ParsCom::getThrowRes;
  this->ptrFunc["pgt"] = &ParsCom::getTakeRes;
  this->ptrFunc["pdi"] = &ParsCom::diePlayer;
  this->ptrFunc["enw"] = &ParsCom::eggPondCase;
  this->ptrFunc["eht"] = &ParsCom::eggBoum;
  this->ptrFunc["ebo"] = &ParsCom::connectEgg;
  this->ptrFunc["edi"] = &ParsCom::dieEgg;
  this->ptrFunc["sgt"] = &ParsCom::getsetTime;
  this->ptrFunc["seg"] = &ParsCom::endTime;
  this->ptrFunc["smg"] = &ParsCom::getMessage;
  this->ptrFunc["suc"] = &ParsCom::incCmd;
  this->ptrFunc["sbp"] = &ParsCom::invalidParam;
}

ParsCom::~ParsCom()
{
}

void		ParsCom::extractParamStr()
{
  int		pos;

  this->_parameters.erase(this->_parameters.begin());
  std::reverse(this->_parameters.begin(), this->_parameters.end());
  pos = this->_parameters.find(' ');
  this->_paramStr = this->_parameters.substr(0, pos);
  this->_parameters.erase(0, pos + 1);
  std::reverse(this->_parameters.begin(), this->_parameters.end());
  std::reverse(this->_paramStr.begin(), this->_paramStr.end());
}

void		ParsCom::extractString(std::string strfunc)
{
  int		pos;

  pos = this->_arg.find(strfunc);
  if (pos == 0)
    this->_exstr = this->_arg.substr(pos, 3);
}

void		ParsCom::extractNumber()
{
  int		pos;
  int		posante;
  int		size;

  size = this->_arg.size();
  pos = this->_arg.find(' ');
  posante = this->_arg.find('\n');
  if (pos > 0 && posante <= size)
    this->_parameters = this->_arg.substr(pos, posante);
}

void		ParsCom::Pars(const std::string & arg)
{
  std::map<std::string, void (ParsCom::*)()>::iterator	it = this->ptrFunc.begin();
  int	pos;

  this->_arg = arg;
  pos = this->_arg.find('\n');
  this->_arg = this->_arg.substr(0, pos);
  for (; it != this->ptrFunc.end() ; ++it)
    {
      extractString((*it).first);
      if (((*it).first.compare(this->_exstr)) == 0)
	(this->*ptrFunc[it->first])();
    }
  this->_exstr.clear();
  this->_arg.clear();
}

void		ParsCom::countSpace(int const &nb)
{
  if (std::count(this->_arg.begin(), this->_arg.end(), ' ') != nb)
    throw Exception("Too many argument");
}

int		ParsCom::convert(std::string const &nbs)
{
  int		nb = 0;

  std::istringstream(nbs) >> nb;
  std::cout << nb << std::endl;
  return (nb);
}

const std::string &	ParsCom::getArg() const
{
  return (this->_arg);
}

void	ParsCom::getMapSize()
{
  this->countSpace(2);
  this->_create->setSize(this->_net->getCmd());
}

void	ParsCom::getAllMap()
{
  this->_create->parseMap(this->_net->getCmd());
}

void	ParsCom::getNameTeam()
{
  int   pos;

  this->extractNumber();
  while (!this->_parameters.empty())
    {
      this->_parameters.erase(this->_parameters.begin());
      pos = this->_parameters.find(' ');
      this->_listTeam.push_back(this->_parameters.substr(0, pos));
      this->_parameters.erase(0, pos);
    }
  std::cout << "tna" << std::endl;
}

void	ParsCom::getConnect()
{
  this->countSpace(6);
  this->extractNumber();
  this->extractParamStr();
  this->_N = this->_paramStr;
  std::istringstream    input(this->_parameters);
  input >> this->_n >> this->_x >> this->_y >> this->_O >> this->_L;
  std::cout << "pnw" << std::endl;
}

void	ParsCom::getPositionPlayer()
{
  this->countSpace(4);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_n >> this->_x >> this->_y >> this->_O;
  this->_create->movePlayer(this->_n, this->_x, this->_y, this->_O);
}

void	ParsCom::getNiveau()
{
  this->countSpace(2);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_n >> this->_L;
  this->_create->lvlUp(this->_n, this->_L);
}

void	ParsCom::getInventaire()
{
  this->countSpace(10);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_n >> this->_x >> this->_y >> this->_0 >> this->_1 >> this->_2 >> this->_3 >> this->_4 >> this->_5 >> this->_6;
  std::cout << "pin" << std::endl;
}

void	ParsCom::getExpulse()
{
  this->countSpace(1);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_n;
  std::cout << "pex" << std::endl;
}

void	ParsCom::getBroadcast()
{
  this->countSpace(2);
  this->extractNumber();
  this->extractParamStr();
  this->_M = this->_paramStr;
  std::istringstream    input(this->_parameters);
  input >> this->_n;
  std::cout << "pbc" << std::endl;
}

void	ParsCom::getIncantation()
{
  int   pos;
  int   tmp;

  this->extractNumber();
  std::istringstream    input(this->_parameters);
  input >> this->_x >> this->_y >> this->_L;
  std::cout << this->_x << this->_y << this->_L << std::endl;
  for (int f_param = 0; f_param != 3; ++f_param)
    {
      this->_parameters.erase(this->_parameters.begin());
      pos = this->_parameters.find(' ');
      this->_parameters.erase(0, pos);
    }
  while (!this->_parameters.empty())
    {
      this->_parameters.erase(this->_parameters.begin());
      pos = this->_parameters.find(' ');
      std::istringstream        input(this->_parameters);
      input >> tmp;
      this->_listPlayer.push_back(tmp);
      this->_parameters.erase(0, pos);
    }
  std::cout << "pic" << std::endl;
}

void	ParsCom::getEndIncantation()
{
  this->countSpace(3);
  this->extractNumber();
  this->extractParamStr();
  this->_R = this->_paramStr;
  std::istringstream    input(this->_parameters);
  input >> this->_x >> this->_y;
  std::cout << "pie" << std::endl;
}

void	ParsCom::getPond()
{
  this->countSpace(1);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_n;
  std::cout << "pfk" << std::endl;
}

void	ParsCom::getThrowRes()
{
  this->countSpace(2);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_n >> this->_i;
  std::cout << "pdr" << std::endl;
}

void	ParsCom::getTakeRes()
{
  this->countSpace(2);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_n >> this->_i;
  this->_create->pickRess(this->_n, this->_i);
}

void	ParsCom::diePlayer()
{
  this->countSpace(1);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_n;
  std::cout << "pdi" << std::endl;
}

void	ParsCom::eggPondCase()
{
  this->countSpace(4);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_e >> this->_n >> this->_x >> this->_y;
  std::cout << "enw" << std::endl;
}

void	ParsCom::eggBoum()
{
  this->countSpace(1);
  std::cout << "eht" << std::endl;
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_e;
}

void	ParsCom::connectEgg()
{
  this->countSpace(1);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_e;
  std::cout << "ebo" << std::endl;
}

void	ParsCom::dieEgg()
{
  this->countSpace(1);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_e;
  std::cout << "edi" << std::endl;
}

void	ParsCom::getsetTime()
{
  this->countSpace(1);
  this->extractNumber();
  std::istringstream	input(this->_parameters);
  input >> this->_T;
  std::cout << "sgt" << std::endl;
}

void	ParsCom::endTime()
{
  this->countSpace(1);
  throw Exception("Serveur send you a kill signal");
  std::cout << "seg" << std::endl;
}

void	ParsCom::getMessage()
{
  this->extractNumber();
  this->_parameters.erase(this->_parameters.begin());
  this->_M = this->_parameters;
  std::cout << this->_arg << std::endl;
}

void	ParsCom::incCmd()
{
  std::cout << this->_arg << std::endl;
}

void	ParsCom::invalidParam()
{
  std::cout << this->_arg << std::endl;
}
