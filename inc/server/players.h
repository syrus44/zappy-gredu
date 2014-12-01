/*
** players.h for Zappy in /home/petit_p//projets/Zappy/zappy-gredu/trunk/sparw
** 
** Made by pierre petit
** Login   <petit_p@epitech.net>
** 
** Started on  Tue Apr 30 10:38:11 2013 pierre petit
** Last update Sat Jul 13 17:51:39 2013 jimmy farcy
*/

#ifndef PLAYERS_H_
# define PLAYERS_H_

# include		<stddef.h>
# include		<stdlib.h>
# include		<stdio.h>
# include		<string.h>
# include		<unistd.h>
# include		"map.h"

#define			ITEM_KIND 7

typedef enum		e_actions
  {
    Move,
    Feed,
    Level_up,
    Gather,
    Lay_egg,
    Expluse,
    Take,
    Pose
  }			actions;

typedef	enum		e_directions
  {
    N	= 1,
    E	= 2,
    S	= 3,
    O	= 4
  }			dirs;

typedef struct          s_players
{
  int			fd;
  int			id;
  char			*name;
  char			*team_name;
  int			time;
  long			time_server;
  struct timeval        start;
  struct timeval        end;
  int			*inv;
  int			pos_x;
  int			pos_y;
  char			*msg;
  int			lvl;
  dirs			d;
  int			objNearX;
  int			objNearY;
  void			(*setposX)(struct s_players *, int );
  void			(*setposY)(struct s_players *, int );
  void			(*setlevel)(struct s_players *, int );
  void			(*setname)(struct s_players *, char *);
  void			(*setTeam)(struct s_players *, char *);
  void			(*setmsg)(struct s_players *, char *);
  int			(*getposX)(struct s_players *);
  int			(*getposY)(struct s_players *);
  int			(*getlevel)(struct s_players *);
  int			(*setInventory)(struct s_players *);
  void			(*showInventory)(struct s_players *);
  void			(*move)(struct s_players *, t_map *, int, int);
}			t_players;

typedef struct		s_elevation
{
  int			lvl;
  void			(*fct)(t_players *, t_map *);
}			t_elevation;

void		init(t_players *);
void		init_values(t_players *);
void		destroy(t_players *);
void		visionPlayer(t_players *, t_map *);
void		visionPlayerNorth(t_players *, t_map *);
void		visionPlayerEast(t_players *, t_map *);
void		visionPlayerSouth(t_players *, t_map *);
void		visionPlayerWest(t_players *, t_map *);
void		showCase(int *);
int		checkCoor(int, int, t_map *);
int		checkCase(int *);
int		IAradius(t_players *, t_map *);
int		getCase(int *);
void            destroy_computer(t_players *);
void		elev1(t_players *, t_map *);
void		elev2(t_players *, t_map *);
void		elev3(t_players *, t_map *);
void		elev4(t_players *, t_map *);
void		elev5(t_players *, t_map *);
void		elev6(t_players *, t_map *);
void		elev7(t_players *, t_map *);
void		elevation(t_players *, t_map *);
void		showInv(t_players *);

#endif		/*_PLAYERS_H_*/
