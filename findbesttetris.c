/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findbesttetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 20:59:19 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/16 20:56:36 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*squaresize(int requiredsize)
{
	char	*sq;
	int		sqsize;
	int		newlines;

	newlines = requiredsize;
	sqsize = ((requiredsize + 1) * requiredsize) + 1; //^2 the rows of characters, + requiredsize is the sum of the '\n' characters, + 1 for the ending '\0'
	printf("size: %d\n", requiredsize);
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

void	ft_figadjust(int **fig, int size, int tetcount)
{
	int x;
	int y;
	int cadj;

	y = 0;
	x = 1;
	cadj = size - 4;
	while (y < tetcount)
	{
		x = 1;
		while (x < 4)
		{
			if ((fig[y][x] > 4) && (fig[y][x] < 9))
				fig[y][x] = (fig[y][x] + cadj);
			else if ((fig[y][x] > 8) && (fig[y][x] < 13))
				fig[y][x] = (fig[y][x] + (cadj * 2));
			else if (fig[y][x] > 12)
				fig[y][x] = (fig[y][x] + (cadj * 3));
			x++;
		}
		y++;

	}
}

int     fillit(char *small_tetris_sq, int *tetconf, int size,  int y)
{
    int ipos;
	int i;
	int sizef;

	i = 0;
	sizef = (size + 1) - 4;
    ipos = placement(small_tetris_sq, tetconf, size);
	printf("ipos = %d\n", ipos);
	printf("this is B: %d\n", tetconf[1]);
	if (ipos == -1)
		return (-1);
	while (i < 4)
	{
		if (i == 0)
			small_tetris_sq[ipos + i++] = y + 65;
		else
			small_tetris_sq[ipos + tetconf[i++]] = y + 65;
	}
	printf("first iter: %s\n", small_tetris_sq);
	printf("tetconf: %d, %d, %d", tetconf[0], tetconf[2], tetconf[3]);
	return (1);
}

char    *recursive_backtrack(char *small_tetris_sq, int **tetconf, int size, int tetcount)
{
    int y;
	int **temptetconf;

	temptetconf = tetconf;
	y = 0;
	printf("%d\n", tetcount);
    while (y < tetcount)
    {
        if (fillit(small_tetris_sq, tetconf[y], size, y) == -1)
        {
			size = size + 1;
			tetconf = temptetconf;
			ft_figadjust(tetconf, size, tetcount);
			small_tetris_sq = squaresize(size);
            //empty_string(small_tetris_sq);
			y = -1;
        }
		y++;
		printf("this is y = %d\n", y);
    }
    return (small_tetris_sq);
}

char    *findbesttetris(int **tetconf, int tetcount)
{
    int     size;
    char    *small_tetris_sq;
	
    size = 4;
    small_tetris_sq = squaresize(size);
    small_tetris_sq = recursive_backtrack(small_tetris_sq, tetconf, size, tetcount);
	return (small_tetris_sq);
}
