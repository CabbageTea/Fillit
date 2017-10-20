# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dglaser <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 14:24:42 by dglaser           #+#    #+#              #
#    Updated: 2017/10/20 00:51:48 by dglaser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PROGRAMNAME = fillit

SRC =	ft_putchar.c \
	  	ft_putstr.c \
	  	ft_memset.c \
	  	ft_memalloc.c \
	  	ft_error.c \
	  	recursive_backtracking.c \
	  	placement.c \
	  	tetrisfigures.c \
	  	main.c \
		ft_onetet.c \
		ft_figadjust.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra -c $(SRC) -g
	gcc $(SRC) -o $(PROGRAMNAME)
clean:
	/bin/rm -f *.o
	rm *~

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
