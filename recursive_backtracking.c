/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_backtracking.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 22:52:55 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/19 04:43:40 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*squaresize(int requiredsize)
{
	char*sq;
	int sqsize;
	int newlines;

	newlines = requiredsize;
	sqsize = ((requiredsize + 1) * requiredsize) + 1;
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

void    empty_grid(char *grid, int y)
{
	char	a;
	int		i;

	i = 0;
	a = (y - 1) + 65;
	while (grid[i] != '\0')
	{
		if (grid[i] == a)
			grid[i] = '.';
		i++;
	}
}

int		fillit(char *grid, int *tetconf, int i, int y, int size)
{
	int t;

	t = 0;
//	printf("tetconf: %d, %d, %d, %d\n", tetconf[0], tetconf[1], tetconf[2], tetconf[3]);
	if (placement(grid, tetconf, size, i) == -1)
		return (-1);
	while (t < 4)
	{
		if (t == 0)
			grid[i] = y + 65;
		else
			grid[i + tetconf[t]] = y + 65;
		t++;
	}
	return (1);
}

int    recursive_backtrack(char *grid, int **tetconf, int y, int size, int tetcount)
{
	int x;

	x = 0;
	while (grid[x] != '\0')
	{
		if (placement(grid, tetconf[y], size, x) != -1)
		{
			fillit(grid, tetconf[y], x, y, size);
			if (y + 1 == tetcount)
				return (--tetcount);
			tetcount = recursive_backtrack(grid, tetconf, y + 1, size, tetcount);
			if (tetcount == y + 1)
			{
				if (tetcount - 1 == 0)
					ft_putstr(grid);
				return (--tetcount);
			}
//			printf("y = %d, x = %d\n, grid :\n%s\n", y, x, grid);
/*			if (y == 0 && grid[x + 1] == '\0')
			{
					x = -1;
					grid = squaresize(++size);
					tetconf = ft_figadjust(tetconf, size, tetcount);
			}*/
		}
		else if (y == 0 && grid[x + 1] == '\0')
		{
			x = -1;
			grid = squaresize(++size);
			tetconf = ft_figadjust(tetconf, size, tetcount);
		}
		x++;
	}
	empty_grid(grid, y);
	return (tetcount);
}

void    findbesttetris(int **tetconf, int tetcount)
{
	int     size;
	char    *grid;
	int y;

	y = 0;
	size = 4;
	grid = squaresize(size);
	recursive_backtrack(grid, tetconf, y, size, tetcount);
}
