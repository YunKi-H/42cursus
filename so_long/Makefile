# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 12:36:14 by yuhwang           #+#    #+#              #
#    Updated: 2022/04/25 07:52:20 by yuhwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
LIBFTDIR		=	../libft
LIBFTFILE		=	libft.a
MINILIBXDIR		=	./minilibx_mms
MINILIBXFILE	=	libmlx.dylib

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

SRCS			=	so_long.c		\
					get_next_line.c	\

OBJS		=	$(SRCS:.c=.o)

$(NAME)		:	$(OBJS)
				$(MAKE) bonus -C $(LIBFTDIR)
				$(MAKE) -C $(MINILIBXDIR)
				cp $(MINILIBXDIR)/$(MINILIBXFILE) $(MINILIBXFILE)
				$(CC) -o $@ $^ $(LIBFTDIR)/$(LIBFTFILE) $(MINILIBXFILE)

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -o $@ -c $< -I.

clean		:
				$(MAKE) -C $(LIBFTDIR) clean
				$(MAKE) -C $(MINILIBXDIR) clean
				$(RM) $(OBJS)

fclean		:	clean
				$(MAKE) -C $(LIBFTDIR) fclean
				$(RM) $(NAME) $(MINILIBXFILE)

re			:
				$(MAKE) fclean
				$(MAKE) all

.PHONY		:	all clean fclean re
