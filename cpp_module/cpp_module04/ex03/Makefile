NAME		=	amateria

CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
INCLUDES	=	-I.
RM			=	rm -f

SRCS		=	main.cpp			\
				AMateria.cpp		\
				ICharacter.cpp		\
				Character.cpp		\
				Cure.cpp			\
				Ice.cpp				\
				IMateriaSource.cpp	\
				MateriaSource.cpp	\

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
