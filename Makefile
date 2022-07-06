##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/start_game.c	\
		src/initiate_structures.c	\
		src/parsing.c	\
		src/getnbr.c	\
		src/destroy.c	\
		src/display_background.c	\
		src/check_player_valid.c	\
		src/text_menu.c	\
		src/compute_fall.c	\
		src/operate_jump.c	\
		src/display.c	\
		src/object.c	\
		src/colision_house.c

OBJ	=	$(SRC:.c=.o)

NAME	=	game

CFLAGS	=	-I./include -g3

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-network -lcsfml-audio

all:	compile

compile:	$(OBJ)
	gcc -c main.c $(CFLAGS) -g3
	gcc -o $(NAME) main.o $(OBJ) $(CFLAGS) $(CSFML)

clean:
	rm -f *.c~
	rm -f *.o src/*.o
	rm -f $(OBJ)
	rm -f $(NAME)

fclean:	clean

re:	fclean all
