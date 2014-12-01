//
// Exception.hh for zappy in /home/caille_l//Documents/client
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Thu May  9 16:31:05 2013 louis cailleux
// Last update Thu Jul  4 17:03:17 2013 jordan bettin
//

#ifndef	EXCEPTION_HH_
# define EXCEPTION_HH_

#include <iostream>
#include <sstream>
#include <stdexcept>

class			Exception : public std::runtime_error
{
public:
  Exception(const char *);
  virtual ~Exception() throw();
  virtual const char *what() const throw();
private:
  std::string msg;
};

#endif			/*EXCEPTION_HH*/
