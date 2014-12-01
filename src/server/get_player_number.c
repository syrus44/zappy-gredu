/*
** get_player_number.c for get_player_number in /home/charle_b//Desktop/System_unix/Zappy/parse_command
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Wed Jun 12 11:06:37 2013 mael charles
** Last update Wed Jun 12 11:10:45 2013 mael charles
*/

#include "commpars.h"

int	get_player_number(char *buff, int i)
{
  int	nb;

  nb = extract_number(buff, i);
  return (nb);
}
