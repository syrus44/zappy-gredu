//
// Parser.cpp for Parser in /home/caille_l//Documents/client
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Thu May  9 15:41:15 2013 louis cailleux
// Last update Thu Jul 11 23:42:02 2013 louis cailleux
//

#include "Parser.hh"

Parser::Parser(std::string const & command)
  : _command (this->removeSpaces(command)), 
    _name(""), _domain("127.0.0.1"), _port(0)
{
  this->cutCommands();
}

Parser::Parser(Parser const &other)
{
  this->_command = other.getCommand();
}

Parser&	Parser::operator=(Parser const &other)
{
  if (&other != this)
    this->_command = other.getCommand();
  return (*this);
}

std::string const &	Parser::getCommand() const
{
  return (this->_command);
}

void	Parser::checkIp()
{
  if (this->it->find("-h") != std::string::npos)
    {
      if (this->jt != this->_cmdtab.end() && this->jt->find("-") == std::string::npos)
	this->_domain = (*jt);
    }
}

void	Parser::toInt(std::string const &str)
{
  int	port;
  std::istringstream iss(str);
  
  iss >> port;
  if (port == std::numeric_limits<int>::max())
    throw Exception("Overflow on the port value");
  this->_port = port;
}

void	Parser::setName()
{
  if (it->find("-n") != std::string::npos)
    {
      if (jt == this->_cmdtab.end())
	throw Exception("Machine name is not defined");
      this->_name = (*jt);
    }
}

void	Parser::checkCommands()
{
  size_t n = this->_cmdtab.size();
  if (!isCmd() || (n != 5 && n != 6))
    throw Exception("Invalid options");
  for (this->it = this->_cmdtab.begin(); it != this->_cmdtab.end(); ++this->it)
    {
      this->jt = this->it;
      ++this->jt;
      if (it->find("-p") != std::string::npos)
	{
	  if ((jt == this->_cmdtab.end()) || 
	      (n = count_if(this->jt->begin(), this->jt->end(), isdigit)) != this->jt->size())
	    throw Exception("Invalid port");
	  this->toInt((*jt));
	}
      this->checkIp();
      this->setName();
    }
  this->checkOrder();
}

void	Parser::cutCommands()
{
  size_t i = 0, j = 0;
  
  for (this->kt = this->_command.begin(); this->kt != this->_command.end(); ++this->kt)
    {
      if ((*this->kt) == ' ')
	{
	  this->_cmdtab.push_back(this->_command.substr(j, (i - j)));
	  j = i + 1;
	}
      if ((i == this->_command.size() - 1))
	this->_cmdtab.push_back(this->_command.substr(j, (i - (j - 1))));
      i++;
    }
}

std::string const	Parser::removeSpaces(std::string const &str) const
{
  std::string		temp;
  std::istringstream	iss(str);
  std::string		result = "";

  while (iss >> temp >> std::ws)
    {
      if (result != "")
	result += " ";
      result += temp;
    }
  return (result);
}

int	Parser::getPort() const
{
  return (this->_port);
}

std::string const & Parser::getName() const
{
  return (this->_name);
}

std::string const & Parser::getDomain() const
{
  return (this->_domain);
}

Parser::~Parser()
{}

bool	Parser::isCmd()
{
  return ((this->_command.find("-p") != std::string::npos && 
	   this->_command.find("-n") != std::string::npos && 
	   this->_command.find("-h") != std::string::npos) ?
	  true : false);
}

void	Parser::checkOrder()
{
  for (this->it = this->_cmdtab.begin(); it != this->_cmdtab.end(); ++this->it)
    {
      this->jt = this->it;
      this->jt++;
      if (it->find("-n") != std::string::npos || it->find("-p") != std::string::npos)
	{
	  if (this->jt->find("-") != std::string::npos)
	    throw Exception("Invalid arguments");
	}
    }
}
