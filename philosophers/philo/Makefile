# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 13:51:47 by yuhwang           #+#    #+#              #
#    Updated: 2022/06/27 17:50:42 by yuhwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=thread -g3
RM			=	rm -f

SRCS		=	philo.c			\
				init.c			\
				utils.c			\
				factory.c		\
				philos_life.c	\
				bool.c			\
				monitor.c		\

OBJS		=	$(SRCS:.c=.o)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) -o $@ $^

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -o $@ -c $<

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:
				$(MAKE) fclean
				$(MAKE) all

.PHONY		:	all clean fclean re
