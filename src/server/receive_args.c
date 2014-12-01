/*
** receive_args.c for receive_args in /home/bettin_j//SVN/zappy-gredu/branches/ZappySockets/src
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Sat May 18 14:05:37 2013 jordan bettin
** Last update Sat Jul 13 17:53:03 2013 jimmy farcy
*/

#include "server.h"

int	receive_args(t_argument *args)
{
  if (args == NULL)
    {
      fprintf(stderr, ERR_RECV);
      return (printFailure(ERR_RECV_END));
    }
  get_protocol(args);
  return (0);
}
