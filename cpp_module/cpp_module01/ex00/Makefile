NAME		=	zombie

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
INCLUDES	=	-I.
RM			=	rm -f

SRCS		=	main.cpp		\
				Zombie.cpp		\
				newZombie.cpp	\
				randomChump.cpp	\

OBJS		=	$(SRCS:.cpp=.o)

$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) -o $@ $^

all			:	$(NAME)

%.o			:	%.cpp
				$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:
				$(MAKE) fclean
				$(MAKE) all

.PHONY		: all clean fclean re
