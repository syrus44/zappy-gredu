/*
** parc_buff.c for parc_buff in /home/charle_b//Desktop/System_unix/Zappy/parse_command
** 
** Made by mael charles
** Login   <charle_b@epitech.net>
** 
** Started on  Tue Jun 11 13:49:23 2013 mael charles
** Last update Fri Jul 12 14:58:33 2013 jimmy farcy
*/

#include "commpars.h"

int	count_cmd(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] && buff[i] != '\n')
    i++;
  return (i);
}

char	*act_cmd(char *buff)
{
  char	*cmd;
  int	i;

  i = 0;
  if ((cmd = malloc(sizeof(char) * count_cmd(buff) + 2)) == NULL)
    return (NULL);
  while (buff[i] != '\0' && buff[i] != '\n')
    {
      cmd[i] = buff[i];
      i++;
    }
  cmd[i] = '\n';
  cmd[i + 1] = '\0';
  free(buff);
  return (cmd);
}

void	inval_com_par(char *buff, int err_value)
{
  if (err_value == -1)
    printf("sbp\n");
  else
    printf("suc\n");
  free(buff);
}

int	parc_buff(char *buff, t_server *serv, int fd, t_list *list)
{
  char	*tmp;
  int	err;

  tmp = epur_str(buff);
  if ((tmp = act_cmd(tmp)) == NULL)
    return (printFailure(MALLOC_FAIL));
  err = commpars(tmp, serv, fd, list);
  if (err == -1 || err == -2)
    {
      inval_com_par(tmp, err);
      free(buff);
      return (-1);
    }
  free(buff);
  free(tmp);
  return (0);
}
