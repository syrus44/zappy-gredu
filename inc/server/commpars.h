/*
** commpars.h for commpars.h in /home/charle_b//Desktop/System_unix/Zappy/parse_command
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Sat May 18 16:25:03 2013 mael charles
** Last update Sat Jul 13 17:47:57 2013 jimmy farcy
*/

#ifndef COMMPARS_H
#define COMMPARS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "server.h"

#define INV_NB "Invalid command, Your number is too big.\n"

struct		s_com
{
  char		*comm;
  int		(*exec)(char *, t_server *, int , t_list *);
}		t_comm;

int	commpars(char *, t_server *, int , t_list *);
int	parc_buff(char *, t_server *, int , t_list *);
int	cont_case(char *, t_server *, int , t_list *);
int	count_number(char *, int);
int	extract_number(char *, int);
int	check_overflow(char *);
int	get_player_number(char *, int);
int	player_position(char *, t_server *, int , t_list *);
int	player_level(char *, t_server *, int , t_list *);
int	player_invent(char *, t_server *, int , t_list *);
int	mod_time(char *, t_server *, int , t_list *);
int	size_map(char *, t_server *, int , t_list *);
int	pa_team(char *, t_server *, int , t_list *);
int	cont_map(char *, t_server *, int , t_list *);
int	get_time(char *, t_server *, int , t_list *);
char	*epur_str(char *);
int	count_space(char *, int );
int	ia_pickres(char *, t_server *, int , t_list *);
int	ia_move(char *, t_server *, int , t_list *);
int	ia_lvlup(char *, t_server *, int , t_list *);
int	look_team(char *, t_server *, int , t_list *);
int	get_player_position(t_client *, t_list *, int , int );
int	get_player_lvl(t_client *, t_list *, int , int );
int	get_player_invent(t_client *, t_list *, int , int );
int	time_ia_action(t_list *, int , long, float);

#endif
