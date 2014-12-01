/*
** argteam.c for argteam in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 10:43:22 2013 mael charles
** Last update Sun Jul 14 18:32:07 2013 mael charles
*/

#include "pars.h"

int	team(char *str, t_argument *argstruct, char **tab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if ((tab[j] = malloc(sizeof(char) * count_char(str, i) + 1)) == NULL)
	return (-1);
      tab[j][count_char(str, i)] = '\0';
      put_string(str, tab[j], i);
      while (str[i] && str[i] != ' ')
	i++;
      i++;
      j++;
    }
  tab[j] = NULL;
  if (check_team(tab) == -1)
    return (-1);
  argstruct->team = tab;
  return (0);
}

int	init_team(char *str, t_argument *argstruct)
{
  char	**tab;

  while (str && *str != ' ')
    str++;
  str++;
  if (*str == '\0')
    {
      printf(INV_TEAM);
      return (-1);
    }
  if ((tab = malloc(sizeof(char *) * (count_word(str) + 1))) == NULL)
    return (-1);
  if (team(str, argstruct, tab) == -1)
    return (-1);
  return (0);
}

int	number_clients(char *str, t_argument *argstruct)
{
  if (check_space(str) > 1)
    {
      printf(INV_CMD);
      return (-1);
    }
  while (*str != ' ')
    str++;
  str++;
  if (check_overflow(str))
    return (-1);
  if (check_neg(str) == -1)
    return (-1);
  if (check_number(str) == -1)
    {
      printf(INV_CLIENT);
      return (-1);
    }
  if ((argstruct->number_clients = atoi(str)) <= 0)
    {
      printf(INV_NB_CLIENT);
      return (-1);
    }
  return (0);
}

int	time_action(char *str, t_argument *argstruct)
{
  if (check_space(str) > 1)
    {
      printf(INV_CMD);
      return (-1);
    }
  while (*str != ' ')
    str++;
  str++;
  if (check_overflow(str))
    return (-1);
  if (check_neg(str) == -1)
    return (-1);
  if (check_number(str) == -1)
    {
      printf(INV_TIME);
      return (-1);
    }
  if ((argstruct->time_action = atoi(str)) <= 0)
    {
      printf(INV_TIME_NB);
      return (-1);
    }
  return (0);
}

