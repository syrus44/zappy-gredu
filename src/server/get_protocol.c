/*
** get_protocol.c for get_protocol in /home/bettin_j//ZappySockets/src
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 10:09:56 2013 jordan bettin
** Last update Sat May 18 14:50:53 2013 jordan bettin
*/

#include		"server.h"

int			get_protocol(t_argument *args)
{
  struct protoent	*pe;

  if (args->port_number < 1024)
    {
      xwrite(2, INV_P, strlen(INV_P));
      return (-1);
    }
  pe = getprotobyname("TCP");
  if (pe == NULL)
    {
      xwrite(2, ERR_PE, strlen(ERR_PE));
      return (-1);
    }
  create_socket(pe, args);
  return (0);
}
