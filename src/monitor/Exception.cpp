//
// Exception.cpp for zappy in /home/caille_l//Documents/client
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Thu May  9 16:31:59 2013 louis cailleux
// Last update Thu Jul  4 17:03:37 2013 jordan bettin
//

#include	"Exception.hh"

Exception::Exception(const char *msg) : std::runtime_error(msg)
{
  std::ostringstream oss;

  oss << msg << ".";
  this->msg = oss.str();
}

Exception::~Exception() throw ()
{}

const char *Exception::what() const throw ()
{
  return (this->msg.c_str());
}
