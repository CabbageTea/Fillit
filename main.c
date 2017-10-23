/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:01:35 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/22 19:03:17 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#define BUF_SIZE 1000

void		ft_checktet(int x, char *buf)
{
	if (buf[x - 2] == '\n')
		ft_error();
}

int			ft_validtets(char *buf, int x, int y, int v)
{
	while (buf[x] != '\0')
	{
		if (buf[x] == '\n')
		{
			if ((((v % 5) != 4) && (v % 20) != 0))
				return (0);
			if ((v % 5) == 4)
			{
				x++;
				v++;
			}
			if (((v % 20) == 0))
			{
				x++;
				y++;
				v = 0;
			}
		}
		x++;
		v++;
		if ((v % 5 == 4) && (buf[x] != '\n'))
			return (0);
	}
	ft_checktet(x, buf);
	return (y - 1);
}

char		**ft_tetsplit(char *buf, int tetcount)
{
	int		x;
	int		y;
	int		i;
	char	**ret;

	x = 0;
	y = 0;
	i = -1;
	ret = (char**)malloc(sizeof(char*) * (tetcount + 1));
	while (y < tetcount)
		ret[y++] = (char*)malloc(sizeof(char) * 21);
	y = 0;
	tetcount = 20;
	while (buf[++i] != '\0')
	{
		if (i != tetcount)
			ret[y][x++] = buf[i];
		if (i == tetcount)
		{
			ret[y++][x] = '\0';
			x = 0;
			tetcount = tetcount + 21;
		}
	}
	return (ret);
}

int			main(int argc, char **argv)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		tets;
	char	**tetstrings;
	int		**tetconf;

	if (argc != 2)
		ft_error();
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	read(fd, buf, BUF_SIZE);
	tets = ft_validtets(buf, 0, 1, 0);
	if (tets == 0)
		ft_error();
	tetstrings = ft_tetsplit(buf, tets);
	tetconf = determinefigures(tetstrings, tets);
	findbesttetris(tetconf, tets);
	return (0);
}
