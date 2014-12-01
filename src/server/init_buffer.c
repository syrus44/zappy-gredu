/*
** init_buffer.c for init_buffer in /home/bettin_j//Buffer2
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Mon Jul  1 12:05:24 2013 jordan bettin
** Last update Sat Jul 13 11:59:51 2013 mael charles
*/

#include	"buffer.h"

t_buffer	*init_buffer(void)
{
  t_buffer	*b;

  b = xmalloc(sizeof(t_buffer));
  if (b == NULL)
    return (NULL);
  b->buffer = xmalloc(sizeof(char) * 1024);
  if (b->buffer == NULL)
    return (NULL);
  b->capacity = 10;
  b->size = 24;
  memset(b->buffer, 0, 1024);
  b->buffer_end = b->buffer + ((b->capacity - 1) * b->size);
  b->write = b->buffer;
  b->read = b->buffer;
  return (b);
}
