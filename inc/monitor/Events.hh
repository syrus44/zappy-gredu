//
// Events.hh for Events in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:50:25 2013 jordan bettin
// Last update Thu Jun 13 17:58:26 2013 jordan bettin
//

#ifndef EVENTS_HH
#define EVENTS_HH

#include <irrlicht.h>

class	Events : public irr::IEventReceiver
{
private:
  bool isKeyDown[irr::KEY_KEY_CODES_COUNT];

public:
  Events();
  ~Events();
  virtual bool OnEvent(const irr::SEvent &);
  virtual bool IsKeyDown(const irr::EKEY_CODE) const;
};

#endif
