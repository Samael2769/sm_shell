##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## ..
##

SRC		=		my_putchar.c \
				my_get_nbr.c \
				my_put_nbr.c \
				my_putstr.c \
				my_strcat.c \
				my_strcmp.c \
				my_strcpy.c \
				my_strlen.c \
				my_strdup.c\
				my_str_to_word_array.c\
				mini_printf.c\
				tab_dup.c\
				my_strncmp.c\
				count_tab.c\
				supp_line.c\
				clean_string.c\
				my_put_error.c\
				read_buff.c\
				find_line.c\
				my_puttab.c\
				free_tab.c\
				add_line.c\
				init_buffer.c\
				count_char.c\

OBJ		=		$(SRC:c=o)

NAME	=		libmy.a

INCLUDE_NAME	=	my.h

#CPPFLAG	=	-Iincludes

all: $(NAME)

$(NAME): $(OBJ)
		@echo -e "\e[0;31m Compiling the LIB... \e[0m"
		@ar rc $(NAME) $(OBJ)
		@cp $(NAME) ../../
		@cp $(INCLUDE_NAME) ../../includes
		@echo -e "\e[0;32m Compilation succesfull!\e[0m"

clean:
		@echo -e "\e[0;31m Deleting .o and .gc objects... \e[0m"
		@$(RM) $(OBJ)

fclean: clean
		@echo -e "\e[0;31m Deleting execs... \e[0m"
		@$(RM) $(NAME)
		@$(RM) ../../$(NAME)

re: fclean all