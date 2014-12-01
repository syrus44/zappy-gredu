/*
** write_into.c for write_into in /home/bettin_j//Buffer2
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Mon Jul  1 12:10:25 2013 jordan bettin
** Last update Tue Jul  2 18:39:14 2013 louis cailleux
*/

#include "server.h"
#include "buffer.h"

void	write_into(t_buffer *buff, char *elem, uint nb)
{
  if (nb > buff->capacity)
    exit_perror("Buffer's full !\n");
  memcpy(buff->write, elem, buff->size);
  if (strlen(buff->write) >= buff->size)
    strcat(buff->write, "\n");
  if (buff->write >= buff->buffer_end)
    buff->write = buff->buffer - buff->size;
  buff->write = buff->write + buff->size;
}
