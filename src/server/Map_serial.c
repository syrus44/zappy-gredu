/*
** Map_serial.c for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Wed Jul 10 01:01:30 2013 louis cailleux
** Last update Sun Jul 14 19:14:48 2013 louis cailleux
*/

#include <unistd.h>
#include "map.h"

extern void	showMap(t_map *this);
extern void	addRessources(t_map *this);
extern int	serialize(t_map *this);

extern void	showMap(t_map *this)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (i < this->max_x)
    {
      while (j < this->max_y)
	{
	  while (k < 5)
	    {
	      printf("%d", this->map[i][j][k]);
	      k++;
	    }
	  printf("\n");
	  k = 0;
	  j++;
	}
      j = 0;
      i++;
    }
}

extern void	addRessources(t_map *this)
{
  int		i;
  int		j;
  size_t	times;
  size_t	n;

  i = 0;
  j = 0;
  srand(time(NULL));
  while (i < this->max_x)
    {
      while (j < this->max_y)
	{
	  times = random() % 4;
	  while (times > 0)
	    {
	      n = random() % 5;
	      if ((i + j + random() % 2) % 2 == 0)
		this->map[i][j][n] = random() % 7;
	      times--;
	    }
	  ++j;
	}
      j = 0;
      i++;
    }
}

void		showSerial(t_map *this)
{
  int		i;

  i = 0;
  while (this->serial[i])
    {
      write(1, &this->serial[i], 1);
      ++i;
    }
}

extern int	serialize(t_map *this)
{
  int		i;
  int		j;
  int		l;
  char		*quant;

  i = 0;
  j = 0;
  l = 0;
  if ((this->serial = malloc(sizeof(char) *
			     ((this->max_x * this->max_y * 26) + 4))) == NULL)
    return (-1);
  while (i < this->max_x)
    {
      while (j < this->max_y)
        {
	  l += sprintf(this->serial + l, "bct %d %d ", i, j);
          if ((quant = quantity(this->map[i][j])) != NULL)
            l += sprintf(this->serial + l, "%s", quant);
	  free(quant);
	  ++j;
        }
      j = 0;
      ++i;
    }
  return (0);
}
