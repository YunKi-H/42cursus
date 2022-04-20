# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 20:22:05 by yuhwang           #+#    #+#              #
#    Updated: 2022/04/20 14:05:55 by yuhwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
SERVER		=	server
CLIENT		=	client

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SERVERSRC	=	server.c
CLIENTSRC	=	client.c

SERVEROBJ	=	$(SERVERSRC:.c=.o)
CLIENTOBJ	=	$(CLIENTSRC:.c=.o)

$(NAME)		:	$(SERVER) $(CLIENT)

$(SERVER)	:	$(SERVEROBJ)
				$(CC) -o $@ $^

$(CLIENT)	:	$(CLIENTOBJ)
				$(CC) -o $@ $^

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -o $@ -c $< -I.

clean		:
				$(RM) $(SERVEROBJ) $(CLIENTOBJ)

fclean		:	clean
				$(RM) $(SERVER) $(CLIENT)

re			:
				$(MAKE) fclean
				$(MAKE) all

.PHONY		:	all clean fclean re
