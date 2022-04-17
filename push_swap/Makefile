# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 20:22:05 by yuhwang           #+#    #+#              #
#    Updated: 2022/04/17 16:28:29 by yuhwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
LIBFTDIR	=	../libft
LIBFTFILE	=	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRCS		=	push_swap.c		\
				ft_atob.c		\
				ft_btoa.c		\
				ft_operators.c	\
				ft_cases.c		\
				ft_stacks.c		\
				ft_parse.c		\

OBJS		=	$(SRCS:.c=.o)

$(NAME)		:	$(OBJS)
				$(MAKE) bonus -C $(LIBFTDIR)
				$(CC) -o $@ $^ $(LIBFTDIR)/$(LIBFTFILE)

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -o $@ -c $< -I.

clean		:
				$(MAKE) -C $(LIBFTDIR) clean
				$(RM) $(OBJS)

fclean		:	clean
				$(MAKE) -C $(LIBFTDIR) fclean
				$(RM) $(NAME)

re			:
				$(MAKE) fclean
				$(MAKE) all

.PHONY		:	all clean fclean re
