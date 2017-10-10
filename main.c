
#include <fcntl.h> 
#include <stdio.h>
#include "libft/libft.h"
#define BUF_SIZE 105
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
			if (((v % 20) == 0) && hcount == 4) //this moves you to the next shape, so it has to have 4 pound symbols. 
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

//int		ft_fourhashes(char **tetstring)
//{

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
	ret = (char**)ft_malloc(sizeof(char*) * (tetcount + 1));
	while((buf[i] != '\0') && (y <= tetcount)) 
	{
		ft_strcpy(ret[y][x],buf[i]);
		if( i == n)
		{
			ret[y][x] = '\0';
			y++;
			x = 0;
			n = n + 21;
		}
		x++;
		i++;
	}
	return(ret);
}

int main (int argc, char **argv)
{
	int fd;
	int ret;
	char buf[BUF_SIZE + 1];
	char *str;
	int tets;
	char **tetstrings = NULL;


	str = NULL;

	if (argc == 2)
		str = argv[1]; //this takes a file name or path from stdin

	fd = open(str, O_RDONLY); //reads the file and returns the size
		if (fd == -1)
		{
			ft_putstr("open() error");
			return (1);
		}
		ret = read(fd, buf, BUF_SIZE); //read returns the size of buf;
		tets = ft_validtets(buf);
		tetstrings = ft_tetsplit(buf, tets);    
		if(tets == 0)
			ft_putstr("your tets are bad");
		printf("  tets = %d", tets);

	 	if(fd == - 1)
		{
			ft_putstr("close() error");
			return (1);
		}
		return (0);
}


