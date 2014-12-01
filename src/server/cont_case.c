/*
** cont_case.c for cont_case in /home/charle_b//Dropbox/Zappy-test/Zappy
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Wed Jul 10 09:49:28 2013 mael charles
** Last update Sun Jul 14 19:23:51 2013 louis cailleux
*/

#include "commpars.h"

int		count_case(char *serial)
{
  int		i;

  i = 0;
  while (*serial && *serial != '\n')
    {
      serial++;
      i++;
    }
  return (i);
}

int		cont_case_send(char *serial, int fd, t_list *list)
{
  int		i;
  char		*sent;

  i = count_case(serial);
  if ((sent = malloc(sizeof(char) * i + 2)) == NULL)
    return (-1);
  snprintf(sent, i + 2, serial);
  if (send_command(list, fd, sent) == -1)
    return (-1);
  return (0);
}

int		cont_case(char *buff, t_server *serv, int fd, t_list *list)
{
  char		*serial;
  int		size;

  (void)list;
  serial = serv->map->serial;
  if (count_space(buff, 2) == -1)
    return (-1);
  while (*serial != '\0')
    {
      size = strlen(buff) - 1;
      if (strncmp(buff, serial, size) == 0)
        {
	  if (cont_case_send(serial, fd, list) == -1)
	    return (-1);
          return (0);
        }
      serial++;
    }
  return (-1);
}
