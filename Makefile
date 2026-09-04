##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile><
##

SRC	=	str_to_word_array.c 	\
		tableau.c 		\
		affiche.c 		\
		help.c 		\
		my_getnbr.c 	\
		parsing.c 		\
		error_in_parse.c 	\
		sprite.c 	\
		init.c 		\
		event.c 	\
		windows.c 	\
		travels.c 	\
		circles.c 	\
		in_circle.c \
		draw_the_time.c 	\
		getting_angles.c 	\
		the_functions_supp.c 	\
		simulation_night.c 		\
		crashing_planes.c 	\
		collisions.c 	\
		flying_plane.c 		\
		events2.c 	\
		off_on_night.c 		\
		animate.c 		\
		initialisation.c 	\
		pause.c 	\
		domaine.c 	\
		crash.c 	\
		crash2.c 	\
		crash3.c 	\
		menu.c 		\
		menu_initialisation.c 	\
		menu_page_settings.c 	\
		menu2.c 	\
		display_the_bonus_plane.c 	\
		crash_bns1.c 	\
		crash_bns2.c 	\
		crash_with_bns_plane.c 	\
		result_checker.c \
		set_text.c 		\
		bonus/parse_for_bonus.c 	\
		guide.c

BNS = 	bonus/bonus_main.c 	\
		bonus/bonus_help.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

BONUS_NAME = 	my_radar_bonus

UNIT_TEST = unit_test

L_FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME) clean

$(NAME):	$(OBJ)
	gcc  $(SRC) main.c $(L_FLAGS) -g3 -lm -o $(NAME)

clean :
	rm -f *vgcore.*
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f *~

fclean: clean
	rm -f coding-style-reports.log
	rm -f $(UNIT_TEST)
	rm -f $(NAME)

re:	fclean all

unit_tests:	fclean $(NAME)
	gcc -o $(UNIT_TEST) $(SRC) tests/unitest.c	\
	--coverage -lcriterion -lgcov -lm

tests_run:	unit_tests
		./$(UNIT_TEST)
		gcovr

push: fclean
	git add .
	git commit -m "Finish the simulation unit_test"
	git push

code: fclean
	coding-style . .
	cat coding-style-reports.log

bonus:	$(BONUS_NAME)	clean

$(BONUS_NAME):
	gcc $(SRC) $(BNS)  $(L_FLAGS) -g3 -lm -o $(NAME)
