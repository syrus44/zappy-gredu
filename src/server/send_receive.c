/*
** send_receive.c for zappy in /home/caille_l//svn/unix/zappy/zappy-gredu/trunk/Zappy
** 
** Made by louis cailleux
** Login   <caille_l@epitech.net>
** 
** Started on  Tue Jul  9 21:13:01 2013 louis cailleux
** Last update Sun Jul 14 19:11:33 2013 louis cailleux
*/

#include "commpars.h"

int		receive_command(int fd, char *elem, t_server *serv, t_list *clist)
{
  int		rd;
  uint		nb;
  int		i;

  nb = 0;
  i = 0;
  if ((rd = recv(fd, elem, 512, 0)) > 0)
    {
      if (nb > serv->buff->capacity)
	nb = 0;
      while (elem[i] && elem[i] != '\n')
	++i;
      elem[i] = '\0';
      write_into(serv->buff, elem, nb);
      memset(elem, 0, strlen(elem));
      nb++;
      do_commands(fd, serv, read_from(serv->buff), clist);
    }
  else
    return (-1);
  return (0);
}

void		do_commands_next(int fd, t_server *serv, char *buf, t_list *clist)
{
  if (serv->fd_grap != -1 || fd != -1)
    parc_buff(buf, serv, fd, clist);
  else
    free(buf);
}

int		do_commands(int fd, t_server *serv, char *buf, t_list *clist)
{
  t_client	*tmp;

  if (strncmp(buf, "GRAPHIC", 7) == 0)
    {
      free(buf);
      if ((tmp = get_client(clist, fd)) != NULL)
	tmp->is_grap = 1;
      if (serv->grap_set == 0)
	{
	  serv->fd_grap = fd;
	  serv->grap_set = 1;
	  if (send_map(clist, serv, serv->fd_grap) == -1)
	    return (-1);
	}
    }
 else if (strncmp(buf, "IA", 2) == 0)
   {
     free(buf);
     serv->id++;
     if (send_map(clist, serv, clist->end->fd_cli) == -1)
       return (-1);
   }
 else
   do_commands_next(fd, serv, buf, clist);
  return (0);
}

int		send_command(t_list *clist, int fd, char *buf)
{
  if (send(fd, buf, strlen(buf), 0) <= 0)
    {
      disconnect_client(clist, fd);
      free(buf);
      return (-1);
    }
  free(buf);
  return (0);
}

int		send_receive(t_server *srv, t_list *clist)
{
  t_client	*current;
  char		*elem;

  elem = xmalloc(sizeof(char) * 512);
  current = clist->begin;
  while (current)
    {
      if (FD_ISSET(current->fd_cli, &(srv->read_fs)))
	{
	  if (current->fd_cli != srv->fd_srv)
	    {
	      if (receive_command(current->fd_cli, elem, srv, clist) == -1)
    		{
		  if (current->fd_cli == srv->fd_grap)
		    srv->grap_set = 0;
		  disconnect_client(clist, current->fd_cli);
		  free(elem);
		  return (-1);
		}
	    }
	}
      current = current->next;
    }
  free(elem);
  return (0);
}
