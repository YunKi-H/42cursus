# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 13:41:48 by dha               #+#    #+#              #
#    Updated: 2022/01/08 22:00:58 by dha              ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c print_c.c print_s.c print_i.c print_u.c print_p.c print_x.c print_ux.c ft_dectohex.c

LIB_DIR = libft
LIB_SRCS = ft_isascii.c ft_putchar_fd.c ft_strchr.c ft_strlen.c ft_substr.c ft_atoi.c \
	ft_isdigit.c ft_memchr.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_bzero.c ft_isprint.c \
	ft_memcmp.c ft_putendl_fd.c  ft_striteri.c ft_strncmp.c ft_toupper.c ft_calloc.c \
	ft_itoa.c ft_memcpy.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isalnum.c ft_memmove.c \
	ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_isalpha.c ft_memset.c ft_split.c \
	ft_strlcpy.c ft_strtrim.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
LIB_DAF = $(LIB_SRCS:%=$(LIB_DIR)/%)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
LIB_OBJS = $(LIB_DAF:.c=.o)
TOT_OBJS = $(OBJS)
TOT_OBJS += $(LIB_OBJS)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(TOT_OBJS)
	ar rcs $@ $^ ft_printf.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./$(LIB_DIR)

clean : 
	$(RM) $(TOT_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean re all