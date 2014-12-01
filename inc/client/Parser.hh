//
// Parser.hh for zappy in /home/caille_l//Documents/client
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Thu May  9 15:26:06 2013 louis cailleux
// Last update Fri May 10 11:49:42 2013 pierre petit
//

#ifndef PARSER_HH_
# define PARSER_HH_

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <limits>
#include "Exception.hh"

class	Parser
{
private:
  std::string				_command;
  std::string				_name;
  std::string				_domain;
  int					_port;
  std::vector<std::string>		_cmdtab;
  std::vector<std::string>::iterator	jt;
  std::vector<std::string>::iterator	it;
  std::string::iterator			kt;

public:
  Parser(std::string const &);
  Parser(Parser const &);
  ~Parser();
  Parser&     operator=(Parser const &);
  std::string const & getCommand() const;
  std::string const removeSpaces(std::string const &) const;
  std::string const & getName() const;
  std::string const & getDomain() const;
  int	getPort() const;
  void	cutCommands();
  void	checkCommands();
  void	checkIp();
  void	setName();
  void	toInt(std::string const &);
  bool	isCmd();
  void	checkOrder();
};

#endif
