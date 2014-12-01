//
// Buffer.hh for Buffer in /home/bettin_j//TC/inc
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Mon Jun 24 16:39:26 2013 jordan bettin
// Last update Fri Jul 12 01:33:16 2013 louis cailleux
//

#ifndef BUFFER_HH
#define BUFFER_HH

#include <boost/circular_buffer.hpp>
#include "Exception.hh"

class	Buffer
{
private:
  boost::circular_buffer<std::string>	cb;
  size_t				capacity;

public:
  Buffer(int const &);
  ~Buffer();
  void	pushElements(const std::string &);
  void	clearBuffer();
  size_t getCapacity() const;
  void	setCapacity(size_t const &);  
  void	displayBuffer() const;
  const std::string & getCurrentElement(unsigned int const &) const;
  void	removeElement(int const &);
};

#endif
