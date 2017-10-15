/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findbesttetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 20:59:19 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/14 17:44:27 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*squaresize(int requiredsize)
{
	char	*sq;
	int		sqsize;
	int		newlines;

	newlines = requiredsize;
	sqsize = (requiredsize ^ 2) + newlines + 1; //^2 the rows of characters, + requiredsize is the sum of the '\n' characters, + 1 for the ending '\0'
	sq = ft_memalloc(sqsize);
	ft_memset(sq, '.', sqsize - 1);
	while (sq[newlines] != '\0')
	{
		sq[newlines] = '\n';
		newlines = newlines + (requiredsize + 1) ;
		if (newlines > sqsize)
			break ;
	}
	sq[sqsize - 1] = '\0';
	return (sq);
}

void    empty_string(char *small_tetris_sq)
{
    int i;

    i = 0;
    while (small_tetris_sq[i] != '\0')
    {
        if (small_tetris_sq[i] != '.' || small_tetris_sq[i] != '\n')
            small_tetris_sq[i] = '.';
        i++;
    }
}
int     fillit(char *small_tetris_sq, int *tetconf, int size,  int y)
{
    int ipos;
	int i;

	i = 0;
    ipos = ft_placement(small_tetris_sq, tetconf, size);
	if (ipos == -1)
		return (-1);
	while (i < 4)
		small_tetris_sq[ipos + tetconf[i++]] = y + 65;
	return (1);
}

int    recursive_backtrack(char *small_tetris_sq, int **tetconf, int size, int tetcount)
{
    int y;

	y = 0;
    while (y < tetcount)
    {
        if (fillit(small_tetris_sq, tetconf[y], size, y) != -1)
        {
			size = size + 1;
			small_tetris_sq = squaresize(size);
            //empty_string(small_tetris_sq);
			y = 0;
        }
		y++;
    }
    return (1);
}

char    *findbesttetris(int **tetconf, int tetcount)
{
    int     size;
    int     configs;
    char    *small_tetris_sq;

    size = 3;
    configs = tetcount ^ 2;
    small_tetris_sq = squaresize(size);
    recursive_backtrack(small_tetris_sq, tetconf, configs, size);
	return (small_tetris_sq);
}
