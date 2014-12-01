/*
** print_ip.c for print_ip in /home/bettin_j//ZappySockets
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 13:54:59 2013 jordan bettin
** Last update Thu Jul 11 21:39:24 2013 jimmy farcy
*/

#include "server.h"

int	print_ip(struct sockaddr_in sin_cli)
{
  char	*ip;

  if ((ip = inet_ntoa(sin_cli.sin_addr)) == NULL)
    return (printFailure(ERR_INET));
  printf(CONNECT, ip);
  return (0);
}
