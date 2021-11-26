# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/24 23:41:04 by yuhwang           #+#    #+#              #
#    Updated: 2021/11/26 12:45:40 by yuhwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_atoi ft_bzero ft_calloc \
		ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint \
		ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset \
		ft_strchr ft_strdup ft_strlcat ft_strlcpy \
		ft_strlen ft_strncmp ft_strnstr ft_strrchr \
		ft_tolower ft_toupper \
		ft_substr ft_strjoin ft_strtrim \
		ft_split ft_itoa ft_strmapi ft_striteri \
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

# BNS_FILES = ft_lstadd_back ft_lstadd_front \
# 			ft_lstclear ft_lstdelone ft_lstiter ft_lstlast \
# 			ft_lstmap ft_lstnew ft_lstsize

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

# BNS_SRCS_DIR = ./
# SRCS = $(addprefix $(BNS_SRCS_DIR), $(addsuffix .c, $(BNS_FILES)))

# BNS_OBJS_DIR = ./
# OBJS = $(addprefix $(BNS_OBJS_DIR), $(addsuffix .o, $(BNS_FILES)))

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
