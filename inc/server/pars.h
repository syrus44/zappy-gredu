/*
** pars.h for pars in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 10:06:03 2013 mael charles
** Last update Sun Jul 14 18:31:46 2013 mael charles
*/

#ifndef  PARS_H
# define PARS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>

# define  MAX_W		1920
# define  MAX_H		1080
# define  MIN_W		5
# define  MIN_H		5
# define  INV_CMD	"Invalid command, Syntax error.\n"
# define  INV_PORT	"Invalid command, The port is not a number.\n"
# define  INV_WIDTH	"Invalid command, The width is not a number.\n"
# define  INV_HEIGHT	"Invalid command, The height is not a number.\n"
# define  INV_TEAM	"Invalid command, The team name is invalid.\n"
# define  INV_CLIENT	"Invalid command, The client is not a number.\n"
# define  INV_NB_CLIENT	"Invalid command, The client's number must be > 0\n"
# define  INV_TIME	"Invalid command, The time is not a number.\n"
# define  INV_TIME_NB	"Invalid command, The time number is not valid.\n"
# define  MULTI_TEAM	"Invalid command, There is name team identical.\n"
# define  INV_ARG	"Invalid command, Your argument is not valid.\n"
# define  INV_NB	"Invalid command, Your number is too big.\n"
# define  INV_MULTI_ARG	"Invalid command, There is too many arg.\n"
# define  INV_NEG	"Invalid command, Negative number.\n"
# define  INV_NBR	"Invalid command, number invalid.\n"
# define  INV_MIN_W	"Invalid command, map width is too small.\n"
# define  INV_MIN_H	"Invalid command, map height is too small.\n"
# define  INV_TEAMNAME	"Invalid command, Team name is invalid.\n"

typedef struct	s_argument
{
  int		port_number;
  int		width;
  int		height;
  char		**team;
  int		number_clients;
  int		time_action;
}		t_argument;

struct		s_arg
{
  char		*arg;
  int		(*exec)(char *, t_argument *);
};

int		main(int , char **);
int		port_number(char *, t_argument *);
int		width(char *, t_argument *);
int		height(char *, t_argument *);
int		init_team(char *, t_argument *);
int		number_clients(char *, t_argument *);
int		time_action(char *, t_argument *);
int		do_char_arg(char **, t_argument *);
int		argpars(char *, t_argument *);
int		check_space(char *);
int		check_number(char *);
int		count_word(char *);
int		count_char(char *, int );
void		put_string(char *, char *, int );
int		check_team(char **);
int		check_overflow(char *);
int		check_miniarg(char **);
int		check_neg(char *);
int		count_arg(char **);
void		free_tab(char **);
void		free_list(t_argument *);
int		printFailure(char *);

#endif
