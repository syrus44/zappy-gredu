/*
** commpars.c for commpars in /home/charle_b//Desktop/System_unix/Zappy/parse_command
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Sat May 18 15:16:31 2013 mael charles
** Last update Tue Jul  9 17:04:30 2013 mael charles
*/

#include "commpars.h"

struct s_com	tabcom[] =
{
  {"msz\n", size_map},
  {"bct ", cont_case},
  {"mct\n", cont_map},
  {"tna\n", pa_team},
  {"ppo ", player_position},
  {"gia ", ia_pickres},
  {"mia ", ia_move},
  {"plv ", player_level},
  {"pin ", player_invent},
  {"sgt\n", get_time},
  {"sst ", mod_time},
  {"lvlu", ia_lvlup},
  {"team", look_team},
  {NULL, NULL},
};

int	commpars(char *buff, t_server *serv, int fd, t_list *list)
{
  int	i;

  i = 0;
  while (tabcom[i].comm != NULL)
    {
      if (strncmp(buff, tabcom[i].comm, 4) == 0)
	{
	  if (tabcom[i].exec(buff, serv, fd, list) == -1)
	    return (-1);
	  return (0);
	}
      i++;
    }
  return (-2);
}
