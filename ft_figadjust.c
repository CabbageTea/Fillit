/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_figadjust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 17:53:54 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/20 21:14:05 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	casezero(int *fig, int size)
{
	int x;
	int factor;

	factor = size - 1;
	x = 1;
	while (x < 4)
	{
		if ((fig[x] > factor) && (fig[x] < (factor * 2 + 1)))
			fig[x] = fig[x] + 1;
		if ((fig[x] > (factor * 2 + 1)) && (fig[x] < (factor * 3 + 2)))
			fig[x] = fig[x] + 2;
		if (fig[x] > (factor * 3 + 2))
			fig[x] = fig[x] + 3;
		x++;
	}
}

void	caseone(int *fig, int size)
{
	int x;
	int factor;

	factor = size - 1;
	x = 1;
	while (x < 4)
	{
		if ((fig[x] > (factor - 1)) && (fig[x] < (factor * 2)))
			fig[x] = fig[x] + 1;
		if ((fig[x] > (factor * 2)) && (fig[x] < (factor * 3 + 1)))
			fig[x] = fig[x] + 2;
		if (fig[x] > (factor * 3 + 1))
			fig[x] = fig[x] + 3;
		x++;
	}
}

void	casetwo(int *fig, int size)
{
	int x;
	int factor;

	factor = size - 1;
	x = 1;
	while (x < 4)
	{
		if ((fig[x] > (factor - 2)) && (fig[x] < (factor * 2 - 1)))
			fig[x] = fig[x] + 1;
		if ((fig[x] > (factor * 2 - 1)) && (fig[x] < (factor * 3)))
			fig[x] = fig[x] + 2;
		if (fig[x] > (factor * 3))
			fig[x] = fig[x] + 3;
		x++;
	}
}

int		**ft_figadjust(int **fig, int size, int tetcount)
{
	int y;

	y = 0;
	if (tetcount <= 2 && size == 3)
		fig = two_tets(fig, tetcount);
	else
	{
		while (y < tetcount)
		{
			if (fig[y][0] == 0)
				casezero(fig[y], size);
			else if (fig[y][0] == 1)
				caseone(fig[y], size);
			else if (fig[y][0] == 2)
				casetwo(fig[y], size);
			y++;
		}
	}
	return (fig);
}
