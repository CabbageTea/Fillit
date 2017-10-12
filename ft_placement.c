int		ft_closetozero(int i, int n)
{
	while (i > n)
	{
		i = i - n;
		if (i < 0)
			return (i + n);
	}
}
int		ft_checkempty(int i, int *smallest_tetrissq, int *figure)
{
	int x;

	x = 0;
	if((smallest_tetrissq[i + figure[1]] == '.') && (smallest_tetrissq[i + figure[2]] == '.')
		   	&& (smallest_tetrissq[i + figure[3i]] == '.'))
		return (1);
	return (0);
}
							
int		ft_placement(int smallest_tetrissq, int *figure, int n)
{
	int x;
	int o;
	int dist;

	x = 0;
	o = 0;
	while(x <= n)
	{
		while(smallest_tetrissq != '\0')
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
	return (0);
}
