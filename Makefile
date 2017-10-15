# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dglaser <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 14:24:42 by dglaser           #+#    #+#              #
#    Updated: 2017/10/14 17:25:32 by dmontoya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar.c \
	  ft_putstr.c \
	  ft_memset.c \
	  ft_memalloc.c \
	  ft_error.c \
	  findbesttetris.c \
	  placement.c \
	  tetrisfigures.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
