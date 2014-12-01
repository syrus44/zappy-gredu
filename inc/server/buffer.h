/*
** buffer.h for buffer in /home/bettin_j//Buffer2
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Mon Jul  1 11:53:06 2013 jordan bettin
** Last update Sat Jul 13 17:49:02 2013 jimmy farcy
*/

#ifndef  BUFFER_H
# define BUFFER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define UNUSED		__attribute__((unused))
# define uint		unsigned int

typedef struct		s_buffer
{
  char			*buffer;
  char			*buffer_end;
  size_t		capacity;
  size_t		size;
  char			*write;
  char			*read;
}			t_buffer;

t_buffer		*init_buffer(void);
void			free_buffer(t_buffer *);
void			write_into(t_buffer *, char *, uint );
char			*read_from(t_buffer *);
void			*xmalloc(size_t );
uint			aff_buffer(t_buffer *, uint );

#endif /*BUFFER_H*/
