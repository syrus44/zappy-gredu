/*
** exit_perror.c for exit_perror in /home/bettin_j//ZappySockets/src
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 10:28:45 2013 jordan bettin
** Last update Thu May  9 10:29:24 2013 jordan bettin
*/

#include "server.h"

int	exit_perror(char *msg)
{
  perror(msg);
  return (-1);
}
