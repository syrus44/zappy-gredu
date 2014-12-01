/*
** Map_quantity.c for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Wed Jul 10 01:02:40 2013 louis cailleux
** Last update Wed Jul 10 01:03:06 2013 louis cailleux
*/

#include "map.h"

void    init_qt(t_qt *qt)
{
  qt->f = 0;
  qt->l = 0;
  qt->d = 0;
  qt->s = 0;
  qt->m = 0;
  qt->p = 0;
  qt->t = 0;
}

char    *quantity(int *box)
{
  char  *quant;
  int   i;
  t_qt  qt;

  i = 0;
  init_qt(&qt);
  if ((quant = malloc(sizeof(char) * 15)) == NULL)
    return (NULL);
  while (i < 5)
    {
      set_quantity(&qt, box[i]);
      ++i;
    }
  sprintf(quant, "%d %d %d %d %d %d %d\n",
	  qt.f, qt.l, qt.d, qt.s, qt.m, qt.p, qt.t);
  return (quant);
}

void	set_quantity(t_qt *qt, int i)
{
  if (i == 0)
    qt->f++;
  if (i == 1)
    qt->l++;
  if (i == 2)
    qt->d++;
  if (i == 3)
    qt->s++;
  if (i == 4)
    qt->m++;
  if (i == 5)
    qt->p++;
  if (i == 6)
    qt->t++;
}
