#include "libft.h"
#include <stdio.h>
#define BUF_SIZE 1000

int	ft_validtets(char *buf) //checks if the file is giving valid tetrominos & returns how many ^_^
{
	int x;
	int y;
	int v;

	x = 0;
	y = 1;
	v = 0;
	while(buf[x] != '\0')
	{
		if(buf[x] == '\n') //newlines can only be in these two spots
		{
			if ((v % 5 == 4) && (buf[x] != '\n'))
			   return (0);
			if ((((v % 5) != 4) && (v % 20) != 0))
				return (0);
			if((v % 5) == 4)
			{
				x++;
				v++;
			}
			if (((v % 20) == 0)) //this moves you to the next shape, so it has to have 4 pound symbols.
			{
				x++;
				y++;
				v = 0;
			}
		}
		x++;
		v++;
	}
	return (y - 1);
}

char	**ft_tetsplit(char *buf, int tetcount) //splits the file into a 2D char array
{
	int		x;
	int		y;
	int		n;
	int		i;
	char	**ret;

	x = 0;
	y = 0;
	n = 20;
	i = 0;
	ret = (char**)malloc(sizeof(char*) * (tetcount + 1));
	while (y < tetcount)
		ret[y++] = (char*)malloc(sizeof(char) * 21);
	y = 0;
	while(buf[i] != '\0')
	{
		if (i != n)
			ret[y][x++] = buf[i];//each string of figurey finishes with \n\0
		if (i == n)
		{
			ret[y][x] = '\0';
			y++;
			x = 0;
			n = n + 21;
		}
		i++;
	}
	return (ret);
}


int main (int argc, char **argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char *str;
	int tets;
	char **tetstrings;
	int		**tetconf;

	str = NULL;
	if (argc == 2)
		str = argv[1]; //this takes a file name or path from stdini
	fd = open(str, O_RDONLY); //reads the file and returns the size
	if (fd == -1)
	{
		ft_putstr("error");
		return (1);
	}
	ret = read(fd, buf, BUF_SIZE); //read returns the size of buf;
	tets = ft_validtets(buf);
	if (tets == 0)
		ft_putstr("error");
	tetstrings = ft_tetsplit(buf, tets);
	tetconf = determinefigures(tetstrings, tets);
	findbesttetris(tetconf, tets);
	if(fd == - 1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}
