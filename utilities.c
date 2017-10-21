/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 22:43:30 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/20 20:23:53 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_determinesize(char *grid)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (grid[i] != '\0')
	{
		if (grid[i++] == '\n')
			size++;
	}
	return (size);
}

char	*squaresize(int requiredsize)
{
	char	*sq;
	int 	sqsize;
	int		newlines;

	newlines = requiredsize;
	sqsize = ((requiredsize + 1) * requiredsize) + 1;
	sq = ft_memalloc(sqsize);
	ft_memset(sq, '.', sqsize - 1);
	while (sq[newlines] != '\0')
	{
		sq[newlines] = '\n';
		newlines = newlines + (requiredsize + 1);
		if (newlines > sqsize)
			break ;
	}
	sq[sqsize - 1] = '\0';
	return (sq);
}

int		**ft_tetconfiguration(char **tetristr, int **tetconf, int y, int hash)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (tetristr[y][i] != '\0')
	{
		if (tetristr[y][i] == '#')
			tetconf[y][x++] = i - hash;
		i++;
	}
	return (tetconf);
}
