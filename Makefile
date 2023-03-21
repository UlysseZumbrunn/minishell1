##
## EPITECH PROJECT, 2023
## B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
## File description:
## Makefile
##

CC	=	gcc

NAME	=	mysh

SRC	=	src/my_sh_first_step.c	\
		src/read_input.c		 \
		src/step4.c		\
		src/gest_process.c		\
		src/step5.c		\
		src/my_fonction.c		\
		src/personnal_function.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I./include/ -g3

CPPFLAGS = -I./include -g

all: 	$(NAME)

$(NAME): 		$(OBJ)
		$(CC) -o $(NAME) $(CPPFLAGS) $(OBJ) $(CFLAGS)

clean:
	rm -f *o $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
