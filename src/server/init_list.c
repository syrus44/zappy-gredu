/*
** init_list.c for zappy in /home/caille_l//Documents/ZappySockets
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Fri May 10 23:36:56 2013 louis cailleux
** Last update Sat May 18 14:48:09 2013 jordan bettin
*/

#include "server.h"

void	init_list(t_list *clist)
{
  clist->begin = NULL;
  clist->end = NULL;
  clist->size = 0;
}
