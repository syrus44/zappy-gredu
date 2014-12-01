//
// Ia.cpp for  in /home/dugast_a//SystemUnix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by antoine dugast
// Login   <dugast_a@epitech.net>
// 
// Started on  Fri Jun 28 14:18:50 2013 antoine dugast

#include	<sstream>
#include	<algorithm>
#include	"Ia.hh"
#include	"Exception.hh"
#include	"Fork.hh"
#include	"WaitPid.hh"
#include	"Usleep.hh"
#include	"Signal.hh"

IA::IA(int const &sizeX, int const &sizeY, int const &fd, std::map<int, std::map<int, std::vector<int> > > const & m)
{
  this->t = new Talk;
  this->id = 0;
  this->team_name = "";
  this->item_number = 7;
  this->name = "";
  this->_map = m;
  this->map_x = sizeX;
  this->map_y = sizeY;
  this->_fd = fd;
  this->pos_x = 0;
  this->pos_y = 0;
  this->d = S;
  this->lvl = 1;
  this->elev[1] = &IA::elev1;
  this->elev[2] = &IA::elev2;
  this->elev[3] = &IA::elev3;
  this->elev[4] = &IA::elev4;
  this->elev[5] = &IA::elev5;
  this->elev[6] = &IA::elev6;
  this->elev[7] = &IA::elev7;
}

IA::~IA()
{}

void		IA::launchIa()
{
  pid_t		pid;
  Usleep	s(300000);
  Fork		f;
  WaitPid	w;
  Signal	t;
  f.cFork();

  if ((pid = f.getPid()) == 0)
    {
      this->setInventory();
      while (this->IAradius() != 0)
	{
	  t.detectSignal();
	  this->move();
	  this->gather();
	  this->lvlup();
	  s.launchSleep();
	}
    }
  else
    {
      w.setPid(pid);
      w.wait();
    }
}

int		IA::IAradius()
{
  for (int r = 0; r != this->map_x; ++r)
    for (int y = -r; y <= r; ++y)
      for (int x = -r; x <= r; ++x)
	{
	  if ((x >= r || y >= r) || (x <= -r || y <= -r))
	    if (this->checkCoor(this->pos_x + x, this->pos_y + y) == 0)
	      if (this->checkCase(this->pos_x + x, this->pos_y + y) == 1)
		{
		  this->showCase(this->_map[pos_y + y][pos_x + x]);
		  this->objNearX = this->pos_x + x;
		  this->objNearY = this->pos_y + y;
		  return (1);
		}
	}
  this->objNearX = this->pos_x;
  this->objNearY = this->pos_y;
  return (0);
}

int		IA::checkCoor(int const &x, int const &y) const
{
  if ((x >= 0 && x <= this->map_x - 1) && (y >= 0 && y <= this->map_y - 1))
    return (0);
  return (-1);
}

int		IA::checkCase(int const & x, int const &y)
{
  size_t n;
  if ((this->it = this->_map.find(x)) != this->_map.end())
    if ((this->jt = it->second.find(y)) != it->second.end())
      if ((n = count_if(jt->second.begin(), jt->second.end(), isGrass)) != jt->second.size())
	return (1);	  
  return (0);
}

void		IA::setMap(std::map<int, std::map<int, std::vector<int> > > const & m)
{
  this->_map = m;
}

bool		isGrass(int x)
{
  return (x == Grass);
}

void		IA::gather()
{
  int			i = getPos();
  std::string		pos("gia ");
  std::stringstream	iss;

  iss << i << " " << this->pos_x << " " << this->pos_y << "\n";
  pos += iss.str();
  this->t->sendMsg(this->_fd, pos);
  this->inv[this->_map[this->pos_x][this->pos_y][i]]++;
  this->_map[this->pos_x][this->pos_y][i] = 7;
}

int		IA::getPos()
{
  if ((this->it = this->_map.find(this->pos_x)) != this->_map.end())
    if ((this->jt = it->second.find(this->pos_y)) != it->second.end())
      for (int i = 0 ; i != NBCASES ; i++)
	if (this->jt->second.at(i) < 7)
	  return (i);
  return (0);
}

void		IA::move()
{
  while (this->pos_x != this->objNearX || this->pos_y != this->objNearY)
    {
      if (this->pos_x < this->objNearX)
	{
	  this->d = E;
	  this->pos_x++;
	}
      if (this->pos_x > this->objNearX)
	{
	  this->d = O;
	  this->pos_x--;
	}
      if (this->pos_y < this->objNearY)
        {
	  this->d = S;
	  this->pos_y++;
	}
      if (this->pos_y > this->objNearY)
	{
	  this->d = N;
	  this->pos_y--;
	}
      this->sendCoord();
    }
}

void	IA::sendCoord() const
{
  std::string		buff("mia ");
  std::stringstream	iss("");
  
  iss << this->id << " " << this->pos_x << " " << this->pos_y << " " << this->d << "\n";
  buff += iss.str();
  this->t->sendMsg(this->_fd, buff);
  buff.clear();
  iss.clear();
}

void	IA::lvlup()
{
  int	i;
  std::string	buff("lvlup\n");

  i = 1;
  while (i != 8)
    {
      if (this->lvl == i)
	if ((this->*elev[i])() == 1)
	  this->t->sendMsg(this->_fd, buff);
      i++;
    }
}

int	IA::checkP()
{
  int	nbP;

  nbP = 1;
  for(int i = 0 ; i < NBCASES ; ++i)   
    {
      if (this->_map[this->pos_x][this->pos_y][i] == Player)
	nbP++;
      i++;
    }
  return (nbP);
}

int	IA::elev1()
{
  if (this->inv[Linemate] >= 1 &&
      this->checkP() == 1)
    {
      this->inv[Linemate]--;
      this->lvl++;
      return (1);
    }
  return (0);
}

int	IA::elev2()
{
  if (this->inv[Linemate] >= 1 &&
      this->inv[Deraumere] >= 1 &&
      this->inv[Sibur] >= 1 &&
      this->checkP() == 2)
    {
      this->inv[Linemate]--;
      this->inv[Deraumere]--;
      this->inv[Sibur]--;
      this->lvl++;
      return (1);
    }
  return (0);
}

int	IA::elev3()
{
  if (this->inv[Linemate] >= 2 &&
      this->inv[Sibur] >= 1 &&
      this->inv[Phiras] >= 2 &&
      this->checkP() == 2)
    {
      this->inv[Linemate] = this->inv[Linemate] - 2;
      this->inv[Sibur]--;
      this->inv[Phiras] = this->inv[Phiras] - 2;
      this->lvl++;
      return (1);
    }
  return (0);
}

int	IA::elev4()
{
  if (this->inv[Linemate] >= 1 &&
      this->inv[Deraumere] >= 1 &&
      this->inv[Sibur] >= 2 &&
      this->inv[Phiras] >= 1 &&
      this->checkP() == 4)
    {
      this->inv[Linemate]--;
      this->inv[Deraumere]--;
      this->inv[Sibur] = this->inv[Sibur] - 2;
      this->inv[Phiras]--;
      this->lvl++;
      return (1);
    }
  return (0);
}

int	IA::elev5()
{
  if (this->inv[Linemate] >= 1 &&
      this->inv[Deraumere] >= 2 &&
      this->inv[Sibur] >= 1 &&
      this->inv[Mendiane] >= 3 &&
      this->checkP() == 4)
    {
      this->inv[Linemate]--;
      this->inv[Deraumere] = this->inv[Deraumere] - 2;
      this->inv[Sibur]--;
      this->inv[Mendiane] = this->inv[Mendiane] - 3;
      this->lvl++;
      return (1);
    }
  return (0);
}

int	IA::elev6()
{
  if (this->inv[Linemate] >= 1 &&
      this->inv[Deraumere] >= 2 &&
      this->inv[Sibur] >= 3 &&
      this->inv[Phiras] >= 1 &&
      this->checkP() == 6)
    {
      this->inv[Linemate]--;
      this->inv[Deraumere] = this->inv[Deraumere] - 2;
      this->inv[Sibur] = this->inv[Sibur] - 3;
      this->inv[Phiras]--;
      this->lvl++;
      return (1);
    }
  return (0);
}

int	IA::elev7()
{
  if (this->inv[Linemate] >= 2 &&
      this->inv[Deraumere] >= 2 &&
      this->inv[Sibur] >= 2 &&
      this->inv[Mendiane] >= 2 &&
      this->inv[Phiras] >= 2 &&
      this->inv[Thystame] >= 1 &&
      this->checkP() == 6)
    {
      this->inv[Linemate] = this->inv[Linemate] - 2;
      this->inv[Deraumere] = this->inv[Deraumere] - 2;
      this->inv[Sibur] = this->inv[Sibur] - 2;
      this->inv[Mendiane] = this->inv[Mendiane] - 2;
      this->inv[Phiras] = this->inv[Phiras] - 2;
      this->inv[Thystame]--;
      this->lvl++;
      return (1);
    }
  return (0);
}

int	IA::getPosX() const
{
  return (this->pos_x);
}

int	IA::getPosY() const
{
  return (this->pos_y);
}
int	IA::getLevel() const
{
  return (this->lvl);
}

void	IA::setPosX(int const &x)
{
  this->pos_x = x;
}

void	IA::setPosY(int const &y)
{
  this->pos_y = y;
}

void	IA::setName(std::string const & name)
{
  this->name = name;
}

void	IA::setTeam(std::string const & team)
{
  this->team_name = team;
}

void	IA::setInventory()
{
  for (int i = 0; i < this->item_number; ++i)
    this->inv.push_back(0);
}

void	IA::affInventory() const
{
  for (int i = 0; i < this->item_number; ++i)
    std::cout << this->inv[i] << std::endl;
}

void	IA::vision(int i) const
{
  if (i == Linemate)
    std::cout << "Linemate";
  if (i == Deraumere)
    std::cout << "Deraumere";
  if (i == Sibur)
    std::cout << "Sibur";
  if (i == Mendiane)
    std::cout << "Mendiane";
  if (i == Phiras)
    std::cout << "Phiras";
  if (i == Thystame)
    std::cout << "Thystame";
  if (i == Player)
    std::cout << "Player";
  std::cout << ",";
}

void	IA::showCase(std::vector<int> tab) const
{
  (void)tab;
  /*
  for (int i = 0 ; i != NBCASES ; ++i)
  vision(tab[i]);*/
}

void	IA::visionIA() const
{
  std::cout << "{";
  if (this->d == N)
    this->visionN();
  if (this->d == E)
    this->visionE();
  if (this->d == S)
    this->visionS();
  if (this->d == O)
    this->visionO();
  std::cout << "}" << std::endl;
}

void	IA::visionN() const
{
  std::map<int, std::map<int, std::vector<int> > >::const_iterator tg;
  int           x;
  int           y;
  int           tmp;

  x = 0;
  y = 0;
  tmp = 1;
  tg = this->_map.begin();
  while (y != -this->lvl)
    {
      while (x != tmp)
        {
          if (this->checkCoor(this->pos_x + x, this->pos_y + y) == 0)
	    this->showCase(tg->second.find(pos_y + y)->second);
          x++;
        }
      x = -tmp;
      tmp += 1;
      y--;
    }
}

void	IA::visionE() const
{
  std::map<int, std::map<int, std::vector<int> > >::const_iterator tg;
  int           x;
  int           y;
  int           tmp;

  x = 0;
  y = 0;
  tmp = 1;
  tg = this->_map.begin();
  while (x != this->lvl)
    {
      while (y != tmp)
        {
	  if (this->checkCoor(this->pos_x + x, this->pos_y + y) == 0)
	    this->showCase(tg->second.find(pos_y + y)->second);
          y++;
        }
      y = -tmp;
      tmp += 1;
      x++;
    }
}

void	IA::visionS() const
{
  std::map<int, std::map<int, std::vector<int> > >::const_iterator tg;
  int           x;
  int           y;
  int           tmp;

  x = 0;
  y = 0;
  tmp = 1;
  tg = this->_map.begin();
  while (y != this->lvl)
    {
      while (x != tmp)
        {
          if (this->checkCoor(this->pos_x + x, this->pos_y + y) == 0)
	    this->showCase(tg->second.find(pos_y + y)->second);
          x++;
        }
      x = -tmp;
      tmp += 1;
      y++;
    }
}

void	IA::visionO() const
{
  std::map<int, std::map<int, std::vector<int> > >::const_iterator tg;
  int           x;
  int           y;
  int           tmp;

  x = 0;
  y = 0;
  tmp = 1;
  tg = this->_map.begin();
  while (x != -this->lvl)
    {
      while (y != tmp)
        {
          if (this->checkCoor(this->pos_x + x, this->pos_y + y) == 0)
	    this->showCase(tg->second.find(pos_y + y)->second);
	  y++;
        }
      y = -tmp;
      tmp += 1;
      x--;
    }
}
