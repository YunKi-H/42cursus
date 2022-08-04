# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuhwang <yuhwang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 19:22:53 by yuhwang           #+#    #+#              #
#    Updated: 2022/08/04 14:28:41 by yuhwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f

SRCS		=	megaphone.cpp	\

OBJS		=	$(SRCS:.cpp=.o)

$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) -o $@ $^

all			:	$(NAME)

%.o			:	$.cpp
				$(CXX) $(CXXFLAGS) -o $@ -c $< -I.

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:
				$(MAKE) fclean
				$(MAKE) all

.PHONY		: all clean fclean re
