# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 12:36:14 by yuhwang           #+#    #+#              #
#    Updated: 2022/04/30 15:12:41 by yuhwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
LIBFTDIR		=	./libft
LIBFTFILE		=	libft.a
MINILIBXDIR		=	./minilibx_mms
MINILIBXLIB		=	libmlx.dylib

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

SRCS			=	so_long.c		\
					parse_ber.c		\
					game_maker.c	\
					key_press.c		\
					valid_check.c	\
					get_next_line.c	\

OBJS		=	$(SRCS:.c=.o)

$(NAME)		:	$(OBJS)
				$(MAKE) bonus -C $(LIBFTDIR)
				$(MAKE) -C $(MINILIBXDIR)
				cp $(MINILIBXDIR)/$(MINILIBXLIB) .
				$(CC) -o $@ $^ $(LIBFTDIR)/$(LIBFTFILE) $(MINILIBXLIB)

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -o $@ -c $< -I.

clean		:
				$(MAKE) -C $(LIBFTDIR) clean
				$(MAKE) -C $(MINILIBXDIR) clean
				$(RM) $(OBJS)

fclean		:	clean
				$(MAKE) -C $(LIBFTDIR) fclean
				$(RM) $(NAME) $(MINILIBXLIB)

re			:
				$(MAKE) fclean
				$(MAKE) all

.PHONY		:	all clean fclean re
