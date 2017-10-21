/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twotets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 01:17:08 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/20 20:38:51 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	case_zero(int *fig)
{
	int x;

	x = 1;
	while (x < 4)
	{
		if (fig[x] > 4 && fig[x] < 9)
			fig[x] = fig[x] - 1;
		if (fig[x] > 9 && fig[x] < 14)
			fig[x] = fig[x] - 2;
		if (fig[x] > 14)
			fig[x] = fig[x] - 3;
		x++;
	}
}

void	case_one(int *fig)
{
	int x;

	x = 1;
	while (x < 4)
	{
		if (fig[x] > 3 && fig[x] < 8)
			fig[x] = fig[x] - 1;
		if (fig[x] > 8 && fig[x] < 13)
			fig[x] = fig[x] - 2;
		if (fig[x] > 13)
			fig[x]= fig[x] - 3;
		x++;
	}
}

void	case_two(int *fig)
{
	int x;

	x = 1;
	while (x < 4)
	{
		if (fig[x] > 2 && fig[x] < 7)
			fig[x] = fig[x] - 1;
		x++;
	}
}

int		**two_tets(int **fig, int tetcount)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (++y != tetcount)
	{
		if (fig[y][0] == 0)
			case_zero(fig[y]);
		else if (fig[y][0] == 1)
			case_one(fig[y]);
		else if (fig[y][0] == 2)
			case_two(fig[y]);
	}
	return (fig);
}
