##
## EPITECH PROJECT, 2021
## $(MAKE)file_105torus
## File description:
## ..
##

DIR	=	sources/

DIR_TEST	=	tests/

DIR_LIB	=	lib/my

CFLAGS	+=	-W -Wall -Wextra

CPPFLAGS	=	-I./includes

LDFLAGS	=	--coverage -lcriterion

SRC_FILES	=	init_env.c\
				mysh.c\
				free_shell.c\
				prompt.c\
				chose_cmd.c\
				check_syscmd.c\
				exec_cmd.c\
				display_things.c\
				unsetenv.c\
				setenv.c\
				change_dir.c\
				error_cd.c\
				complex_cmd.c\
				redirect.c\
				redirect2.c\
				main.c\
				pipe.c\

SRC_FILES_TEST	=\

SRC	=	$(addprefix $(DIR), $(SRC_FILES))

SRC_TEST	=	$(addprefix $(DIR_TEST), $(SRC_FILES_TEST))

OBJ	=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

NAME	=	sm_shell

LIB_FLAG	= -L. -lmy

TEST_NAME	=	unitest

CC	=	gcc

COVERAGE	=	gcovr

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -sC $(DIR_LIB)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LIB_FLAG)

unit_test: $(OBj) $(OBJ2)
		$(MAKE) -sC $(DIR_LIB)
		$(CC) -o $(TEST_NAME) $(SRC) $(SRC_TEST) $(LDFLAGS) $(CPPFLAGS) $(LIB_FLAG)

clean:
		$(RM) -f *.gc* $(OBJ)
		$(MAKE) -sC $(DIR_LIB) clean

fclean: clean
		$(RM) -f $(NAME) $(TEST_NAME)
		$(MAKE) -sC $(DIR_LIB) fclean

tests_run: fclean unit_test
			./$(TEST_NAME)
			$(COVERAGE) --exclude $(DIR_TEST)
			$(COVERAGE) -b --exclude $(DIR_TEST)

re: fclean $(NAME)

.PHONY: all unit_test clean fclean tests_run re