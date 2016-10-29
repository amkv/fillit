# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 10:59:16 by akalmyko          #+#    #+#              #
#    Updated: 2016/10/28 19:39:12 by akalmyko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
CFILES = main.c ft_console.c
CFILES += ft_putchar.c ft_putstr.c
CFILES += ft_strcpy.c ft_strnew.c ft_bzero.c ft_strncpy.c
CFILES += ft_readfile.c ft_tetro_splitter.c ft_exit_error.c
CFILES += ft_ptest.c ft_putnstr.c ft_validator.c ft_smart_validator.c
CFILES += ft_tetriminos.c ft_grid.c ft_putgrid.c ft_tetro_move.c
CFILES += ft_border.c ft_fillit.c
OFILES = $(CFILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	clear
	@#$(CC) $(FLAGS) -c $(CFILES)
	@$(CC) -c $(CFILES)
	@$(CC) $(FLAGS) $(OFILES) -o $(NAME)
	@#./tetri-gen -i -f +5
	@#./tetri-gen -v -f +5
	@#cat sample.fillit | cat -e
	@#./fillit text
	@#clear && gcc -g -fsanitize=address $(FLAGS) $(CFILES) -o fillit
	@./fillit text

fo: clean
	@$(CC) $(FLAGS) -c $(CFILES)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
