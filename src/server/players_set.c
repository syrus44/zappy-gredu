/*
** players.c for players in /home/bettin_j//ZappyObjects/include
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Tue May  7 16:33:54 2013 jordan bettin
** Last update Sun Jul 14 19:13:14 2013 louis cailleux
*/

#include "players.h"

static void	setposX(t_players *this, int x);
static void	setposY(t_players *this, int y);
extern void	setlevel(t_players *this, int l);
extern void	setname(t_players *this, char *name);
extern void	setTeam(t_players *this, char *team);
extern void	setmsg(t_players *this, char *msg);
extern int	getposX(t_players *this);
extern int	getposY(t_players *this);
extern int	getlevel(t_players *this);
extern int	setInventory(t_players *this);

void		init_values(t_players *this)
{
  this->name = NULL;
  this->team_name = NULL;
  this->inv = NULL;
  this->msg = NULL;
  this->pos_x = 0;
  this->pos_y = 0;
  this->lvl = 1;
  this->fd = 0;
  this->d = 1;
}

void		init(t_players *this)
{
  init_values(this);
  this->setposX = &setposX;
  this->setposY = &setposY;
  this->setlevel = &setlevel;
  this->setname = &setname;
  this->setmsg = &setmsg;
  this->setTeam = &setTeam;
  this->getposX = &getposX;
  this->getposY = &getposY;
  this->getlevel = &getlevel;
  this->setInventory = &setInventory;
}

void		destroy(t_players *this)
{
  this->setposX = NULL;
  this->setposY = NULL;
  this->setlevel = NULL;
  this->setname = NULL;
  this->setmsg = NULL;
  this->setTeam = NULL;
  this->getposX = NULL;
  this->getposY = NULL;
  this->getlevel = NULL;
  this->setInventory = NULL;
  if (this->msg)
    free(this->msg);
  if (this->name)
    free(this->name);
  if (this->inv)
    free(this->inv);
  if (this->team_name)
    free(this->team_name);
  free(this);
}

static void	setposX(t_players *this, int x)
{
  if (this == NULL)
    return ;
  this->pos_x = x;
}

static void	setposY(t_players *this, int y)
{
  if (this == NULL)
    return ;
  this->pos_y = y;
}
