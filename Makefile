##
## Makefile for Makefile in /home/bettin_j//ZappySockets
## 
## Made by jordan bettin
## Login   <bettin_j@epitech.net>
## 
## Started on  Thu May  9 10:39:09 2013 jordan bettin
## Last update Sun Jul 14 19:41:30 2013 mael charles
##

SERV		=	server
SRC_SD		=	./src/server
INC_SD		=	./inc/server/

SRC_S		=	$(SRC_SD)/main.c		\
			$(SRC_SD)/listen_connexions.c	\
			$(SRC_SD)/exit_perror.c		\
			$(SRC_SD)/fill_infos_sock.c	\
			$(SRC_SD)/bind_socket.c		\
			$(SRC_SD)/create_socket.c	\
			$(SRC_SD)/Map.c			\
			$(SRC_SD)/get_protocol.c	\
			$(SRC_SD)/xwrite.c		\
			$(SRC_SD)/xclose.c		\
			$(SRC_SD)/xmalloc.c		\
			$(SRC_SD)/check_port.c		\
			$(SRC_SD)/players_get.c		\
			$(SRC_SD)/players_set.c		\
			$(SRC_SD)/Map_get.c		\
			$(SRC_SD)/Map_set.c		\
			$(SRC_SD)/Map_serial.c		\
			$(SRC_SD)/Map_quantity.c	\
			$(SRC_SD)/objects_xy.c		\
			$(SRC_SD)/objects_res.c		\
			$(SRC_SD)/init_fdsets.c		\
			$(SRC_SD)/init_clients.c	\
			$(SRC_SD)/select_fds.c		\
			$(SRC_SD)/accept_connexions.c	\
			$(SRC_SD)/client_list.c		\
			$(SRC_SD)/players.c		\
			$(SRC_SD)/print_ip.c		\
			$(SRC_SD)/xselect.c		\
			$(SRC_SD)/initEverything.c	\
			$(SRC_SD)/deleteEverything.c	\
			$(SRC_SD)/init_list.c		\
			$(SRC_SD)/init_buffer.c		\
			$(SRC_SD)/argpars.c		\
			$(SRC_SD)/argserv.c		\
			$(SRC_SD)/argteam.c		\
			$(SRC_SD)/check_miniarg.c	\
			$(SRC_SD)/check_neg.c		\
			$(SRC_SD)/check_number.c	\
			$(SRC_SD)/check_overflow.c	\
			$(SRC_SD)/check_space.c		\
			$(SRC_SD)/check_team.c		\
			$(SRC_SD)/count_char.c		\
			$(SRC_SD)/send_receive.c	\
			$(SRC_SD)/count_word.c		\
			$(SRC_SD)/do_char_arg.c		\
			$(SRC_SD)/receive_args.c	\
			$(SRC_SD)/send_map.c		\
			$(SRC_SD)/map_modif.c		\
			$(SRC_SD)/write_into.c		\
			$(SRC_SD)/read_from.c		\
			$(SRC_SD)/put_string.c		\
			$(SRC_SD)/free_list.c		\
                        $(SRC_SD)/command.c             \
			$(SRC_SD)/get_command.c		\
			$(SRC_SD)/elevation.c		\
			$(SRC_SD)/elevation5-7.c	\
			$(SRC_SD)/elevation1-4.c	\
                        $(SRC_SD)/commpars.c            \
			$(SRC_SD)/ia_commands.c		\
			$(SRC_SD)/ia_action.c		\
                        $(SRC_SD)/count_space.c         \
                        $(SRC_SD)/epur_str.c            \
                        $(SRC_SD)/extract_number.c      \
                        $(SRC_SD)/get_player_number.c   \
			$(SRC_SD)/disconnect_client.c	\
                        $(SRC_SD)/parc_buff.c           \
			$(SRC_SD)/utils.c		\
                        $(SRC_SD)/simple_com.c		\
			$(SRC_SD)/look_team.c		\
			$(SRC_SD)/cont_case.c		\
			$(SRC_SD)/free_struct.c

OBJS		=	$(SRC_S:.c=.o)

CLIENT		=	monitor
SRC_CD		=	./src/monitor
INC_CD		=	./inc/monitor/

SRC_C		=	$(SRC_CD)/main.cpp		\
			$(SRC_CD)/Parser.cpp		\
			$(SRC_CD)/Exception.cpp		\
			$(SRC_CD)/Network.cpp		\
			$(SRC_CD)/Talk.cpp		\
			$(SRC_CD)/Map.cpp		\
			$(SRC_CD)/Thystame.cpp		\
			$(SRC_CD)/Sibur.cpp		\
			$(SRC_CD)/Mendiane.cpp		\
			$(SRC_CD)/Player.cpp		\
			$(SRC_CD)/Phiras.cpp		\
			$(SRC_CD)/Linemate.cpp		\
			$(SRC_CD)/Deraumere.cpp		\
			$(SRC_CD)/Cube.cpp		\
			$(SRC_CD)/AObjects.cpp		\
			$(SRC_CD)/ASphere.cpp		\
			$(SRC_CD)/Events.cpp		\
			$(SRC_CD)/Text.cpp		\
			$(SRC_CD)/Food.cpp		\
			$(SRC_CD)/CreateMap.cpp		\
			$(SRC_CD)/ParseCom.cpp		\
			$(SRC_CD)/Buffer.cpp		\
			$(SRC_CD)/Signal.cpp

OBJC		=	$(SRC_C:.cpp=.o)

IA		=	client
SRC_IAD		=	./src/client
INC_IAD		=	./inc/client/

SRC_IA		=	$(SRC_IAD)/main.cpp		\
			$(SRC_IAD)/Talk.cpp		\
			$(SRC_IAD)/Buffer.cpp		\
			$(SRC_IAD)/mapIA.cpp		\
			$(SRC_IAD)/Fork.cpp		\
			$(SRC_IAD)/Signal.cpp		\
			$(SRC_IAD)/Exception.cpp	\
			$(SRC_IAD)/Parser.cpp		\
			$(SRC_IAD)/ParsCom.cpp		\
			$(SRC_IAD)/Network.cpp		\
			$(SRC_IAD)/Usleep.cpp		\
			$(SRC_IAD)/WaitPid.cpp		\
			$(SRC_IAD)/Ia.cpp

OBJIA		=	$(SRC_IA:.cpp=.o)

RM		=	rm -f

DUST_S		=	$(INC_SD)/*~ $(INC_SD)\#*\# *~ \#*\# $(SRC_SD)/*~ $(SRC_SD)/\#*\#
DUST_C		=	$(INC_CD)/*~ $(INC_CD)\#*\# *~ \#*\# $(SRC_CD)/*~ $(SRC_CD)/\#*\#
DUST_IA		=	$(INC_IAD)/*~ $(INC_IAD)\#*\# *~ \#*\# $(SRC_IAD)/*~ $(SRC_IAD)/\#*\#

CC_S		=	gcc
CC_C		=	g++

CFLAGS		=	-W -Wall -Werror -I$(INC_SD)
CPPFLAGS	=	-Wall
FXFLAGS		=	-I/usr/local/include/irrlicht -I/usr/X11R6/include -I$(INC_CD) 
IAFLAGS		=	-I$(INC_IAD) -W -Werror -Wextra

LDFLAGS		=	-L/usr/X11R6/lib -L/usr/local/lib -lIrrlicht -lGL -lXxf86vm -lXext -lX11 -lXcursor

all		:	$(SERV) $(CLIENT) $(IA)

$(OBJC)		:	CPPFLAGS+= $(FXFLAGS)

$(OBJIA)	:	CPPFLAGS+= $(IAFLAGS)

$(SERV)		:	$(OBJS)
		$(CC_S) -o $(SERV) $(OBJS)

$(CLIENT)	:	$(OBJC)
		$(CC_C) $(LDFLAGS) -o $(CLIENT) $(OBJC)

$(IA)		:	$(OBJIA)
		$(CC_C) $(LDFLAGS) -o $(IA) $(OBJIA)

dust		:
		$(RM) $(DUST_C) $(DUST_S) $(DUST_IA)

clean		:	dust
		$(RM) $(OBJS)
		$(RM) $(OBJC)
		$(RM) $(OBJIA)

cleanser	:
		$(RM) $(OBJS)

cleancli	:
		$(RM) $(OBJC)

cleania		:
		$(RM) $(OBJIA)

fclean		:	clean
		$(RM) $(SERV) $(CLIENT) $(IA)

re		:	fclean all
