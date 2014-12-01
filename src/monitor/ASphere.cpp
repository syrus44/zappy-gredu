//
// Sphere.cpp for ASphere in /home/bettin_j//ZappyClient
// 
// Made by jordan bettin
// Login   <bettin_j@epitech.net>
// 
// Started on  Thu Jun 13 17:09:26 2013 jordan bettin
// Last update Fri Jul 12 01:23:16 2013 louis cailleux
//

#include "ASphere.hh"

ASphere::ASphere(irr::video::IVideoDriver *d, irr::scene::ISceneManager *s, int const &x, int const &y, int const &z)
{
  this->drv = d;
  this->scn = s;
  this->name = "Unknown";
  this->posX = x;
  this->posY = y;
  this->posZ = z;
}

ASphere::~ASphere()
{}
