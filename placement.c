/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:37:42 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/12 20:37:50 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_closetozero(int i, int n)
{
	while (i > n)
	{
		i = i - n;
		if (i < 0)
			return (i + n);
	}
}
int	ft_checkempty(int i, char *smallest_tetrissq, int *figure)
{
	int x;

	x = 0;
	if((smallest_tetrissq[i + figure[1]] == '.') && (smallest_tetrissq[i + figure[2]] == '.')
	   && (smallest_tetrissq[i + figure[3]] == '.'))
		return (1);
	return (0);
}

int	ft_placement(char *smallest_tetrissq, int *figure, int n)
{
	int x;
	int i;
	int dist;

	x = 0;
	i = 0;
	while(x <= n)
	{
		while(smallest_tetrissq[i] != '\0')
		{
			if(smallest_tetrissq[i] == '.')
			{
				dist = ft_closetozero(i, n);
				if(x == dist)
				{
					if(ft_checkempty(i, smallest_tetrissq, figure) == 1)
						return (i);
				}
			}
			i++;
		}
		x++;
	}
	return (-1);
}