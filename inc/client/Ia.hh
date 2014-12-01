//
// Ia.hh for  in /home/dugast_a//SystemUnix/zappy/zappy-gredu/trunk/Zappy
// 
// Made by antoine dugast
// Login   <dugast_a@epitech.net>
// 
// Started on  Fri Jun 28 14:19:43 2013 antoine dugast
// Last update Fri Jul 12 00:29:58 2013 louis cailleux
//

#ifndef			IA_HH
#define			IA_HH

#include		<iostream>
#include		<map>
#include		<vector>
#include		"Talk.hh"

#define			NBCASES 5

typedef enum		e_directions
  {
    N	= 1,
    E	= 2,
    S	= 3,
    O	= 4
  }			dir;

typedef enum            e_ressources
  {
    Food,
    Linemate,
    Deraumere,
    Sibur,
    Mendiane,
    Phiras,
    Thystame,
    Grass,
    Player
  }                     resource;

class			IA
{
private:
  int			id;
  Talk			*t;
  std::string		name;
  std::string		team_name;
  std::map<int, std::map<int, std::vector<int> > >		_map;
  std::map<int, std::map<int, std::vector<int> > >::iterator	it;
  std::map<int, std::vector<int> >::iterator			jt;
  std::map<int, int (IA::*)()>					elev;
  int			pos_x;
  int			pos_y;
  int			map_x;
  int			map_y;
  int			_fd;
  int			item_number;
  int			objNearX;
  int			objNearY;
  dir			d;
  std::vector<int>	inv;
  int			lvl;
public:
  IA(int const &, int const &, int const &, std::map<int, std::map<int, std::vector<int> > > const &);
  ~IA();
  void			launchIa();
  int			IAradius();
  void			gather();
  void			move();
  void			setMap(std::map<int, std::map<int, std::vector<int> > > const &);
  int			checkCoor(int const &, int const &) const;
  int			checkCase(int const &, int const &);
  int			getPos();
  int			getPosX() const;
  int			getPosY() const;
  int			getLevel() const;
  void			affInventory() const;
  void			setPosX(int const &);
  void			setPosY(int const &);
  void			sendCoord() const;
  void			setName(std::string const &);
  void			setInventory();
  void			setTeam(std::string const &);
  void			lvlup();
  int			elev1();
  int			elev2();
  int			elev3();
  int			elev4();
  int			elev5();
  int			elev6();
  int			elev7();
  void			visionIA() const;
  void			visionN() const;
  void			visionE() const;
  void			visionS() const;
  void			visionO() const;
  void			showCase(std::vector<int>) const;
  void			vision(int) const;
  int			checkP();
};

bool			isGrass(int);

#endif			/*IA_HH*/
