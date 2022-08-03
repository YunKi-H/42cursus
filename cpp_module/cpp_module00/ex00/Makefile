NAME		=	megaphone

CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -f

SRCS		=	megaphone.cpp	\

OBJS		=	$(SRCS:.cpp=.o)

$(NAME)		:	$(OBJS)
				$(CPP) $(CPPFLAGS) -o $@ $^

all			:	$(NAME)

%.o			:	$.cpp
				$(CPP) $(CPPFLAGS) -o $@ -c $< -I.

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:
				$(MAKE) fclean
				$(MAKE) all

.PHONY		: all clean fclean re
