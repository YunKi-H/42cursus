NAME		=	phonebook

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f

SRCS		=	PhoneBook.cpp	\
				main.cpp		\

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
