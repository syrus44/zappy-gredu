/*
** read_from.c for read_from in /home/bettin_j//Buffer2
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Mon Jul  1 13:32:38 2013 jordan bettin
** Last update Sat Jul 13 16:17:28 2013 mael charles
*/

#include "server.h"
#include "buffer.h"

char	*read_from(t_buffer *buff)
{
  char	*to_read;

  if ((to_read = xmalloc(sizeof(char) * 512)) == NULL)
    return (NULL);
  memset(to_read, 0, 512);
  if (buff->capacity == 0)
    exit_perror("Buffer's empty !\n");
  memcpy(to_read, buff->read, buff->size);
  if (strlen(buff->read) >= buff->size)
    strcat(to_read, "\n");
  if (buff->read >= buff->buffer_end)
    buff->read = buff->buffer - buff->size;
  buff->read = buff->read + buff->size;
  return (to_read);
}
