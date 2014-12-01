/*
** xmalloc.c for xmalloc in /home/bettin_j//ZappySockets
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Thu May  9 10:48:30 2013 jordan bettin
** Last update Tue Jul  2 21:39:09 2013 louis cailleux
*/

#include "server.h"

void	*xmalloc(size_t nb)
{
  void	*ptr;

  ptr = malloc(nb);
  if (ptr == NULL)
    {
      xwrite(2, ERR_MALLOC, strlen(ERR_MALLOC));
      return (NULL);
    }
  return (ptr);
}
