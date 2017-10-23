/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:37:42 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/22 16:21:36 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkempty(int i, char *grid, int *fig, int n)
{
	int x;
	int o;

	o = ((n + 1) * n);
	x = 0;
	if (((i + fig[1]) > o) || ((i + fig[2]) > o) || ((i + fig[3]) > o))
		return (0);
	if ((grid[i + fig[1]] == '.') && (grid[i + fig[2]] == '.')
			&& (grid[i + fig[3]] == '.'))
		return (1);
	return (0);
}

int	placement(char *smallest_tetrissq, int *figure, int n, int i)
{
	if (smallest_tetrissq[i] == '.')
	{
		if (ft_checkempty(i, smallest_tetrissq, figure, n) == 1)
			return (i);
	}
	return (-1);
}
