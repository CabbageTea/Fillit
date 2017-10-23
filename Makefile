# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dglaser <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 14:24:42 by dglaser           #+#    #+#              #
#    Updated: 2017/10/23 14:43:39 by dmontoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	ft_putchar.c \
	  	ft_putstr.c \
	  	ft_memset.c \
	  	ft_memalloc.c \
	  	ft_error.c \
	  	recursive_backtracking.c \
	  	placement.c \
	  	tetrisfigures.c \
	  	main.c \
		ft_figadjust.c \
		utilities.c \
		ft_twotets.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) *.c -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
