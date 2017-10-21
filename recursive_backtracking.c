/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_backtracking.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 22:52:55 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/20 21:34:50 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	empty_grid(char *grid, int y)
{
	char	a;
	int		i;

	i = 0;
	if (y == 0)
		y++;
	a = (y - 1) + 65;
	while (grid[i] != '\0')
	{
		if (grid[i] == a)
			grid[i] = '.';
		i++;
	}
}

int		fillit(char *grid, int *tetconf, int i, int y)
{
	int t;

	t = 0;
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

int		recursive_backtrack(char *grid, int **tetconf, int y, int tetcount)
{
	int	x;

	x = -1;
	while (grid[++x] != '\0')
	{
		if (placement(grid, tetconf[y], ft_determinesize(grid), x) != -1)
		{
			fillit(grid, tetconf[y], x, y);
			if (y + 1 != tetcount)
				tetcount = recursive_backtrack(grid, tetconf, y + 1, tetcount);
			if (tetcount == y + 1)
			{
				if (tetcount - 1 == 0)
					ft_putstr(grid);
				return (--tetcount);
			}
		}
		else if (grid[x + 1] == '\0' && y == 0)
		{
			x = -1;
			grid = squaresize(ft_determinesize(grid) + 1);
			tetconf = ft_figadjust(tetconf, ft_determinesize(grid), tetcount);
		}
	}
	empty_grid(grid, y);
	return (tetcount);
}

void	ft_onetet(int *tetconf)
{
	int x;

	x = 2;
	tetconf[x++] = 3;
	tetconf[x] = 4;
}
void	findbesttetris(int **tetconf, int tetcount)
{
	int		size;
	char	*grid;
	int		y;

	y = 0;
	if (tetcount == 1 && tetconf[0][1] == 1 && tetconf[0][2] == 5 && tetconf[0][3] == 6)
	{
		ft_onetet(tetconf[0]);
		grid = squaresize(2);
		tetcount = recursive_backtrack(grid, tetconf, y, tetcount);
	}
	size = 3;
	if (tetcount <= 2 && tetcount > 0 && size == 3)
	{
		tetconf = ft_figadjust(tetconf, size, tetcount);
		grid = squaresize(size);
		tetcount = recursive_backtrack(grid, tetconf, y, tetcount);
		if (tetcount > 0)
			tetconf = ft_figadjust(tetconf, size, tetcount);
	}
	if (tetcount != 0)
	{
		size = 4;
		grid = squaresize(size);
		recursive_backtrack(grid, tetconf, y, tetcount);
	}
}
