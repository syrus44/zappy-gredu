//
// Buffer.cpp for Buffer in /home/bettin_j//TC/inc
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Mon Jun 24 16:44:17 2013 jordan bettin
// Last update Fri Jul 12 01:22:30 2013 louis cailleux
//

#include "Buffer.hh"

Buffer::Buffer(int const &capacity)
{
  boost::circular_buffer<std::string> tmp(capacity);

  this->cb = tmp;
  this->setCapacity(capacity);
}

Buffer::~Buffer()
{
  this->cb.clear();
}

void	Buffer::pushElements(const std::string & newInput)
{
  unsigned int	cpt = 0;

  if (cpt == this->capacity)
    cpt = this->capacity;
  this->cb.push_front(newInput);
  cpt += 1;
}

void	Buffer::clearBuffer()
{
  int	cpt = 0;

  for (boost::circular_buffer<std::string>::iterator it = this->cb.begin() ; it != this->cb.end() ; ++it)
    {
      this->cb.pop_front();
      cpt += 1;
    }
  std::cout << "Removed " << cpt << " elements (total of elements stored before : " << this->getCapacity() << ")" << std::endl;
}

void	Buffer::displayBuffer() const
{
  for (boost::circular_buffer<std::string>::const_iterator it = this->cb.begin() ; it != this->cb.end() ; ++it)
    std::cout << (*it) << std::endl;
}

void	Buffer::removeElement(int const &pos)
{
  this->cb.at(pos).clear();
}

size_t	Buffer::getCapacity() const
{
  return (this->capacity);
}

void	Buffer::setCapacity(size_t const &c)
{
  this->capacity = c;
}

const std::string &	Buffer::getCurrentElement(unsigned int const &pos) const
{
  return (this->cb[pos]);
}
