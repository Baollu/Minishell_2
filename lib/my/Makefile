##
## EPITECH PROJECT, 2024
## Make
## File description:
## File
##

SRC	=	my_isneg.c			\
		my_putstr.c			\
		my_str_to_word_array.c		\
		my_putchar.c			\
		my_sort_int_array.c		\
		my_swap.c			\
		my_getnbr.c			\
		my_put_nbr.c			\
		my_strlen.c			\
		mini_printf.c			\
		my_strcmp.c			\
		my_strcat.c			\
		my_strdup.c			\
		my_strncmp.c			\
		my_strcpy.c			\
		my_split_str.c			\
		is_str.c			\
		nbr_str.c			\

OBJ	=	$(SRC:.c=.o)

AR	?=	ar

NAME	=	libmy.a

NAMEPATH =	../

CFLAGS = -g3 -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
	$(RM) -f $(OBJ)
	$(RM) -f $(NAME) $(NAMEPATH)$(NAME)

fclean: clean

re: all fclean

.PHONY: all clean fclean re
