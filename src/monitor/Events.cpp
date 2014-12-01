//
// Events.cpp for Events in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:53:17 2013 jordan bettin
// Last update Wed Jun 19 11:35:44 2013 pierre petit
//

#include "Events.hh"

Events::Events()
{
  for (irr::u32 i = 0 ; i < irr::KEY_KEY_CODES_COUNT ; ++i)
    this->isKeyDown[i] = false;
}

Events::~Events()
{}

bool	Events::OnEvent(const irr::SEvent & event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    this->isKeyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  return (false);
}

bool	Events::IsKeyDown(const irr::EKEY_CODE keyCode) const
{
  return (this->isKeyDown[keyCode]);
}
