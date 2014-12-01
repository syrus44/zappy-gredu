/*
** argserv.c for argservf in /home/charle_b//Desktop/System_unix/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Thu May  9 10:38:45 2013 mael charles
** Last update Thu Jul 11 16:50:15 2013 mael charles
*/

#include "pars.h"

int	port_number(char *str, t_argument *argstruct)
{
  if (check_space(str) > 1)
    {
      printf(INV_CMD);
      return (-1);
    }
  while (*str != ' ')
    str++;
  str++;
  if (check_overflow(str) == -1)
    return (-1);
  if (check_neg(str) == -1)
    return (-1);
  if (check_number(str) == -1)
    {
      printf(INV_PORT);
      return (-1);
    }
  argstruct->port_number = atoi(str);
  return (0);
}

int	width_next(char *str, t_argument *argstruct)
{
  if ((argstruct->width = atoi(str)) == -1)
    return (-1);
  if (argstruct->width < MIN_W)
    {
      printf(INV_MIN_W);
      return (-1);
    }
  return (0);
}

int	width(char *str, t_argument *argstruct)
{
  if (check_space(str) > 1)
    {
      printf(INV_CMD);
      return (-1);
    }
  while (*str != ' ')
    str++;
  str++;
  if (check_overflow(str) == -1)
    return (-1);
  if (check_neg(str) == -1)
    return (-1);
  if (check_number(str) == -1)
    {
      printf(INV_WIDTH);
      return (-1);
    }
  if (width_next(str, argstruct) == -1)
    return (-1);
  return (0);
}

int	height_next(char *str, t_argument *argstruct)
{
  if ((argstruct->height = atoi(str)) == -1)
    return (-1);
  if (argstruct->height < MIN_H)
    {
      printf(INV_MIN_H);
      return (-1);
    }
  return (0);
}

int	height(char *str, t_argument *argstruct)
{
  if (check_space(str) > 1)
    {
      printf(INV_CMD);
      return (-1);
    }
  while (*str != ' ')
    str++;
  str++;
  if (check_overflow(str) == -1)
    return (-1);
  if (check_neg(str) == -1)
    return (-1);
  if (check_number(str) == -1)
    {
      printf(INV_HEIGHT);
      return (-1);
    }
  if (height_next(str, argstruct) == -1)
    return (-1);
  return (0);
}
