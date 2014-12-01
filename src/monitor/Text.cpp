//
// Text.cpp for Zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Fri Jul  5 16:48:38 2013 louis cailleux
// Last update Fri Jul 12 01:03:12 2013 louis cailleux
//

#include "Text.hh"

Text::Text(irr::scene::ISceneManager *smgr, irr::IrrlichtDevice *device)
{
  this->smgr = smgr;
  this->draw = false;
  this->strdraw = false;
  this->font = device->getGUIEnvironment()->getBuiltInFont();
}

Text::Text(Text const & other)
{
  this->_displayed = other.getDisplayed();
  this->draw = other.isDisplayed();
}

Text::~Text()
{
}

Text&	Text::operator=(Text const &other)
{
  if (this != &other)
    {
      this->draw = other.isDisplayed();
      this->_displayed = other.getDisplayed();
    }
  return (*this);
}

irr::scene::IBillboardTextSceneNode * const	Text::getDisplayed() const
{
  return (this->_displayed);
}

void	Text::remove()
{
  this->_displayed->remove();
}

void	Text::removeStr()
{
  this->_string->remove();
}

void	Text::levelUp(int const &x, int const & y)
{
  this->_displayed = this->smgr->addBillboardTextSceneNode(this->font, L"Level up", 0, irr::core::dimension2d< irr::f32 >(125.0f, 50.0f), irr::core::vector3df((x + 1) * 100, 375, (y + 1) * 100), -1, irr::video::SColor(100, 255, 0, 0), irr::video::SColor(100, 255, 0, 0)); 
}

void	Text::affText(std::string const &str, irr::core::dimension2d< irr::f32 > const & size, irr::core::vector3df const &pos, irr::video::SColor const & cl)
{
  std::wstring widestr = std::wstring(str.begin(), str.end());
  this->_string = this->smgr->addBillboardTextSceneNode(this->font, widestr.c_str(), 0, size, pos, -1, cl, cl); 
}

void	Text::setDisplayed(bool const & b)
{
  this->draw = b;
}

bool	Text::isDisplayed() const
{
  return (this->draw);
}

void	Text::strDisplayed(bool const &b)
{
  this->strdraw = b;
}

bool	Text::isStrDisplayed() const
{
  return (this->strdraw);
}
