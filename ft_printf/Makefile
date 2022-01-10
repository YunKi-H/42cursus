# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 14:28:32 by yuhwang           #+#    #+#              #
#    Updated: 2022/01/11 00:04:23 by yuhwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFTDIR	=	./libft
LIBFTFILE	=	libft.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rcs
RM			=	rm -f

SRCS		=	ft_printf.c \
				ft_print_c.c \
				ft_print_s.c \
				ft_print_di.c \
				ft_print_hex.c

OBJS		=	$(SRCS:.c=.o)

$(NAME)		:	$(OBJS)
				$(MAKE) bonus -C $(LIBFTDIR)
				cp $(LIBFTDIR)/$(LIBFTFILE) $(NAME)
				$(AR) $@ $^

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -o $@ -c $< -I.

clean		:
				$(MAKE) -C $(LIBFTDIR) clean
				$(RM) $(OBJS)

fclean		:	clean
				$(MAKE) -C $(LIBFTDIR) fclean
				$(RM) $(NAME)

re			:	clean all

.PHONY		:	all clean fclean re
