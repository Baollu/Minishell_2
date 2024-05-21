##
## EPITECH PROJECT, 2023
## test
## File description:
## test
##

SRC	=	src/main.c		\
		src/set_linkedlist.c	\
		src/find_path.c 	\
		src/execute_path.c	\
		src/take_command.c	\
		src/minishell.c		\
		src/exit.c		\
		src/env.c		\
		src/find_func.c		\
		src/set_env.c		\
		src/cd.c		\
		src/check_setenv.c	\
		src/is_separator.c	\
		src/pipe.c		\
		src/read_write_pipe.c	\
		src/what_separator.c	\
		src/great_than.c	\
		src/semicolon.c		\
		src/less_than.c		\
		src/clean_str.c		\

CFLAGS	=	-g3 -Wall -Wextra

CPPFLAGS = 	-iquote ./include

LIBPATH = 	./lib/my

FLAGS	=	-L $(LIBPATH) -lmy

NAME	=	mysh

OBJ	=	$(SRC:.c=.o)

CC	?=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C $(LIBPATH)
		$(CC) -o $(NAME) $(OBJ) $(FLAGS)

clean:
	$(MAKE) clean -C $(LIBPATH)
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

debug: FLAGS +=	-g3
debug: re

.PHOMY: all clean fclean re debug
