/*
** irc_srv.h for irc_srv in /home/bettin_j//Dropbox/Epitech/Projets/MyIRC
** 
** Made by jordan bettin
** Login   <bettin_j@epitech.net>
** 
** Started on  Sat Apr 20 17:20:02 2013 jordan bettin
** Last update Sun Jul 14 19:06:00 2013 louis cailleux
*/

#ifndef	  __SERVER_H___
# define  __SERVER_H__

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <netdb.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <ctype.h>
# include "players.h"
# include "map.h"
# include "objects.h"
# include "pars.h"
# include "buffer.h"

# define UNUSED		__attribute__((unused))
# define USAGE		"Usage: ./server\n -p [port number]\n -x [width map]\n"
# define USAGE_SUITE	"-y [heigh map]\n -n [name_team1] [name_team2] [...]\n"
# define USAGE_END	"-c [number of client per team]\n -t [time per action]\n"
# define CONNECT	"Client is connected with : %s\n"
# define ACCEPT_FAIL	"Error : getprotobyname  failed\n"
# define SOCKET_FAIL	"Invalid port number or socket already created\n"
# define INV_P		"The port must be a value greather than 1024\n"
# define ERR_PE		"Failed to get a TCP port\n"
# define ERR_SETSOCK	"Failed to set sock options\n"
# define ERR_INET	"Failed to convert Internet adress\n"
# define ERR_CLI	"Failed to create the client list\n"
# define ERR_MALLOC	"Not enough memory space for allocation\n"
# define ERR_PORT	"The port isn't composed of numerical digits\n"
# define FATAL_ERROR	"Select's timeout ended ! Now exiting ...\n"
# define ERR_RECV	"Invalid pointer for the argument structure"
# define ERR_RECV_END	" ! Now exiting ...\n"

# define END		"The time is elapsed ! The game is finished\n"

# define MALLOC_FAIL	"Error : the syscall malloc failed\n"
# define STRDUP_FAIL	"Error : the syscall strdup failed\n"
# define READ_FAIL	"Error : the syscall read failed\n"
# define WRITE_FAIL	"Error : the syscall write failed\n"
# define OPEN_FAIL	"Error : the syscall open failed\n"
# define SEND_FAIL	"Error : the syscall send failed\n"
# define RECV_FAIL	"Error : the syscall recv failed\n"
# define CLOSE_FAIL	"Error : the syscall close failed\n"
# define SEND_COMMAND	"Error : can't send command\n"

# define BUFFER_FULL	"Warning : ring buffer is full\n"
# define BUFFER_EMPTY	"Warning : ring buffer is empty\n"

# define MAX_CLIENT	"Max number of clients reached\n"
# define PORT_ALR_USE	"The port is already used\n"

typedef struct		s_server
{
  int			fd_srv;
  struct sockaddr_in	sin_srv;
  fd_set		read_fs;
  int			id;
  int			max_fd;
  int			fd_grap;
  int			grap_set;
  char			**all_team;
  struct timeval	tv;
  long			time;
  t_map			*map;
  t_buffer		*buff;
  t_objects		*objects;
}			t_server;

typedef struct		s_client
{
  t_players		*player;
  int			fd_cli;
  int			is_grap;
  struct sockaddr_in	sin_cli;
  struct s_client	*prev;
  struct s_client	*next;
}			t_client;

typedef	struct		s_list
{
  struct s_client	*begin;
  struct s_client	*end;
  unsigned int		size;
}			t_list;

int		receive_args(t_argument *);
int		get_protocol(t_argument *);
int		create_socket(struct protoent *, t_argument *);
int		fill_infos_sock(t_server *, t_argument *);
int		bind_socket(t_server *, t_argument *);
int		listen_connexions(t_server *, t_argument *);
int		exit_perror(char *);
int		xclose(int);
int		init_fdsets(t_server *, t_argument *);
int		init_clients(t_server *, t_client *);
int		accept_connexions(t_server *, t_list *);
int		check_port(char *);
int		print_ip(struct sockaddr_in);
void		*xmalloc(size_t);
int		xrecv(int , void *, size_t , int );
int		xselect(int, fd_set *, fd_set *,
		fd_set *, struct timeval *);
int		select_fds(t_server *, t_list *, t_argument *);
int		xwrite(int, const void *, size_t);
int		initEverything(t_server *, t_argument *);
int		deleteEverything(t_server *, t_list *, t_argument *);
int		add_empty(t_list *, t_server * , t_client *);
int		add_end(t_list *, t_client *, int, t_server *);
void		show_list(t_list *);
void		delete_all(t_list *);
void		init_list(t_list *);
int		send_map(t_list *, t_server *, int);
int		map_modif(int, int, int, t_server *);
int		send_receive(t_server *, t_list *);
int		setmaxfd(t_server *, t_list *);
int		send_command(t_list *, int, char *);
int		receive_command(int, char *, t_server *, t_list *);
void		clientIA(t_server *, t_list *);
int		welcome(t_server *, t_list *);
int		disconnect_client(t_list *, int);
t_client	*get_client(t_list *, int);
int		send_modif(t_list *, t_server *, char *);
int		pick_buf(t_server *, t_list *, int, int);
int		client_handle(t_server *, int, char *, t_list *);
int		do_commands(int, t_server *, char *, t_list *);
void		free_srv(t_server *);
int		IAgather(t_list *, t_players *, t_map *);
int		send_coord(t_list *, t_players *);
void		launchIA(t_list *, t_players *, t_map *);
void		IAmove(t_list *, t_players *);
int		*handle_tab(char *, int, int);
long int	get_diff_time(struct timeval, struct timeval);
int		get_time_cmd(float , float );
int		send_again(t_server *, t_list *);
void		free_struct(t_argument *);

#endif	/*SERVER*/
