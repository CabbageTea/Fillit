# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dglaser <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 14:24:42 by dglaser           #+#    #+#              #
#    Updated: 2017/10/14 18:05:42 by dmontoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PROGRAMNAME = fillit

SRC = ft_putchar.c \
	  ft_putstr.c \
	  ft_memset.c \
	  ft_memalloc.c \
	  ft_error.c \
	  findbesttetris.c \
	  placement.c \
	  tetrisfigures.c \
	  main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra -c $(SRC)
	gcc $(SRC) -o tetris

clean:
	/bin/rm -f *.o
	rm *~

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
