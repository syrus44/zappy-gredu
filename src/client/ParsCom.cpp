//
// ParsCom.cpp for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Sat Jun 29 13:41:37 2013 louis cailleux
// Last update Fri Jul 12 00:11:13 2013 louis cailleux
//

#include "ParsCom.hh"

ParsCom::ParsCom(mapIA *create, Network *net, Talk *talk)
{
  this->_create = create;
  this->_net = net;
  this->_talk = talk;
  this->_arg = "";
  this->_exstr = "";
  this->_parameters = "";
  this->_paramStr = "";
  this->ptrFunc["msz"] = &ParsCom::getMapSize;
  this->ptrFunc["bct"] = &ParsCom::getAllMap;
  this->ptrFunc["seg"] = &ParsCom::endTime;
  this->ptrFunc["tco"] = &ParsCom::lookTeam;
}

ParsCom::~ParsCom()
{}

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

void		ParsCom::lookTeam()
{
  throw Exception("Your team name is not in the server");
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

void		ParsCom::Pars(std::string & arg)
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

void		ParsCom::countSpace(int nb) const
{
  if (std::count(this->_arg.begin(), this->_arg.end(), ' ') != nb)
    throw Exception("Too many argument");
}

int		ParsCom::convert(std::string const & nbs) const
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

void	ParsCom::endTime()
{
  this->countSpace(1);
  std::cout << this->_net->getCmd() << std::endl;
}
