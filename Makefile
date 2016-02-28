##
## Makefile for sokoban in /home/bauren_a/Work/tek-1/PSU/semestre_2/PSU_2015_my_sokoban
## 
## Made by Arthur
## Login   <bauren_a@epitech.net>
## 
## Started on  Thu Feb 25 20:14:30 2016 Arthur
## Last update Sun Feb 28 18:52:38 2016 Arthur
##

NAME	=	my_sokoban

SRC	=	main.c		\
		game.c		\
		core.c		\
		player.c	\
		string.c	\
		freeer.c	\
		termcaps.c

OBJ	=	$(SRC:.c=.o)

INCLUDE	=	-I./include/

CFLAGS	+=	$(INCLUDE) -g


all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re

