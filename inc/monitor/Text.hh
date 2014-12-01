//
// Text.hh for Zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by louis cailleux
// Login   <caille_l@epitech.net>
// 
// Started on  Fri Jul  5 16:43:58 2013 louis cailleux
// Last update Fri Jul 12 01:02:55 2013 louis cailleux
//

# ifndef TEXT_HH_
# define TEXT_HH_

#include <irrlicht.h>
#include <iostream>

class	Text
{
  irr::scene::IBillboardTextSceneNode	*_displayed;
  irr::scene::IBillboardTextSceneNode	*_string;
  irr::scene::ISceneManager		*smgr;
  irr::gui::IGUIFont			*font;		
  bool					draw;
  bool					strdraw;

public:
  Text(irr::scene::ISceneManager *, irr::IrrlichtDevice *);
  Text(Text const &);
  ~Text();
  void remove();
  void removeStr();
  Text & operator=(Text const &);
  irr::scene::IBillboardTextSceneNode * const	getDisplayed() const;
  void	levelUp(int const &, int const &);
  bool	isDisplayed() const;
  void	setDisplayed(bool const &);
  bool	isStrDisplayed() const;
  void	strDisplayed(bool const &);
  void	affText(std::string const &str, irr::core::dimension2d< irr::f32 > const & size, irr::core::vector3df const & pos, irr::video::SColor const & cl);
};

#endif
