/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:37:42 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/19 01:04:13 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_closetozero(int i, int n)
{
	while (i > n)
	{
		i = i - n;
		if (i < 0)
			return (i + n);
	}
	return (i);
}

int	ft_checkempty(int i, char *smallest_tetrissq, int *figure, int n)
{
	int x;
	int o;

	o = ((n + 1) * n);
	x = 0;
	if(((i + figure[1]) > o) || ((i + figure[2]) > o) || ((i + figure[3]) > o))
			return (0);
	if((smallest_tetrissq[i + figure[1]] == '.') && (smallest_tetrissq[i + figure[2]] == '.')
	   && (smallest_tetrissq[i + figure[3]] == '.'))
		return (1);
	return (0);
}

int	placement(char *smallest_tetrissq, int *figure, int n, int i)
{
//	int x;
//	int dist;

//	x = 0;
	if(smallest_tetrissq[i] == '.')
	{
		if(ft_checkempty(i, smallest_tetrissq, figure, n) == 1)
			return (i);
	}
	return (-1);
}
