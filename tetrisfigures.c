/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrisfigures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 20:02:00 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/22 16:33:38 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	mallocintarray(int **tetconf, int tetcount)
{
	int i;

	i = 0;
	while (tetcount-- > 0)
		tetconf[i++] = (int*)malloc(sizeof(int) * 4);
}

int		ft_hashcount(char *onetet)
{
	int i;
	int hcount;

	i = 0;
	hcount = 0;
	while (i < 21)
	{
		if (onetet[i] == '#')
			hcount += 1;
		i++;
	}
	if (hcount == 4)
		return (1);
	return (-1);
}

int		ft_checkvalidtet(int *tc)
{
	if (tc[1] == 1)
		if (((tc[2] == 2) && (tc[3] == 6)) || ((tc[2] == 2) && (tc[3] == 3))
			|| ((tc[2] == 5) && (tc[3] == 10)) || ((tc[2] == 2) && (tc[3] == 7))
			|| ((tc[2] == 6) && (tc[3] == 11)) || ((tc[2] == 2) && (tc[3] == 5))
			|| ((tc[2] == 5) && (tc[3] == 6)) || ((tc[2] == 6) && (tc[3] == 7)))
			return (0);
	if (((tc[1] == 5) && (tc[2] == 6) && (tc[3] == 10)) ||
			((tc[1] == 5) && (tc[2] == 10) && (tc[3] == 15)) ||
			((tc[1] == 5) && (tc[2] == 6) && (tc[3] == 7)) ||
			((tc[1] == 5) && (tc[2] == 10) && (tc[3] == 11)) ||
			((tc[1] == 5) && (tc[2] == 6) && (tc[3] == 11)))
		return (0);
	if (((tc[1] == 4) && (tc[2] == 5) && (tc[3] == 6)) ||
			((tc[1] == 4) && (tc[2] == 5) && (tc[3] == 10)) ||
			((tc[1] == 5) && (tc[2] == 9) && (tc[3] == 10)) ||
			((tc[1] == 1) && (tc[2] == 4) && (tc[3] == 5)) ||
			((tc[1] == 4) && (tc[2] == 5) && (tc[3] == 9)))
		return (1);
	if ((tc[1] == 3) && (tc[2] == 4) && (tc[3] == 5))
		return (2);
	ft_error();
	return (-1);
}

int		findfirsthash(char *tetristr)
{
	int i;

	i = 0;
	if (ft_hashcount(tetristr) == -1)
		ft_error();
	while (tetristr[i] != '\0')
	{
		if (tetristr[i] == '#')
			return (i);
		i++;
	}
	return (-1);
}

int		**determinefigures(char **tetristr, int tetcount)
{
	int	**tetconf;
	int y;
	int hash;

	y = 0;
	tetconf = (int **)malloc(sizeof(int*) * tetcount);
	mallocintarray(tetconf, tetcount);
	while (y < tetcount)
	{
		hash = findfirsthash(tetristr[y]);
		tetconf = ft_tetconfiguration(tetristr, tetconf, y, hash);
		tetconf[y][0] = ft_checkvalidtet(tetconf[y]);
		y++;
	}
	return (tetconf);
}
