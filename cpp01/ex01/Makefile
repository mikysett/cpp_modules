MAKEFLAGS	+=	--quiet

WHT	= \033[0;37m
BLK	= \033[0;30m
RED	= \033[0;31m
YEL	= \033[0;33m
BLU	= \033[0;34m
GRN	= \033[0;32m

NAME	=	zombie

DIR_S	=	

DIR_O	=	obj

SRCS		:= main.cpp Zombie.cpp ZombieHorde.cpp

OBJS		:= $(SRCS:%.cpp=$(DIR_O)/%.o)

# Using wildcards: $(shell find $(HEADERS) -name *.h)
DEPS	=	$(shell find *.hpp)

CC		=	clang++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address

RM		=	rm -f

$(DIR_O)/%.o: %.cpp
			@mkdir -p $(DIR_O)
			$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME):	$(DEPS) $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS)
			printf "$(WHT)[$(GRN)$(NAME) COMPILED$(WHT)]\n"

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			printf "$(WHT)[$(YEL)$(NAME) OBJS REMOVED$(WHT)]\n"

fclean:		clean
			$(RM) $(NAME)
			$(RM) -d $(DIR_O)
			printf "$(WHT)[$(YEL)$(NAME) BINARIES REMOVED$(WHT)]\n"

re:			fclean all

debug:		INCLUDES += -DDEBUG_MODE
debug:		CFLAGS += -g -fsanitize=address
debug:		clean
debug:		all

.PHONY:		all clean fclean re debug