/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrisfigures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 20:02:00 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/10 20:02:02 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "tetris.h"

void    mallocintarray(int **tetconf, int tetcount)
{
    int i;

    i = 0;
    while (tetcount-- > 0)
        tetconf[i++] = (int*)malloc(sizeof(int) * 4);//addprotectionformalloc???
}

void    accomodatefigure(int *tetconf, int temp) //sets the figure configuration to the coordinates most upper left of the square 
{
    int i;
    int counter;
    int adjfactor;
    int y;

    i = 0;

    counter = 4;
    while
    if (temp > 0)
    {
        adjfactor = tetconf[0];
        while (counter-- > 0)
            tetconf[i] = tetconf[i++] - adjfactor;
    }
    else
        return ;
}
int *ft_checkvalidtet(int *tetconfig)
{
    if (tetconfig[1] == 1)
        if (((tetconfig[2] == 2) && (tetconfig[3] == 6)) || ((tetconfig[2] == 2) && (tetconfig[3] == 3)) || ((tetconfig[2] == 5) && (tetconfig[3] == 10))
         || ((tetconfig[2] == 2) && (tetconfig[3] == 7)) || ((tetconfig[2] == 6) && (tetconfig[3] == 11)) || ((tetconfig[2] == 2) && (tetconfig[3] == 5))
         || ((tetconfig[2] == 5) && (tetconfig[3] == 6)) || ((tetconfig[2] == 6) && (tetconfig[3] == 7)))
            return (0);
        


    }
}

int     **determinefigures(char **tetristr, int tetcount) //determines the configuration of each figure/square given by the file
{
    int **tetconf;
    int x;
    int y;
    int i;
    int temp;

    y = 0;
    temp = 0;
    tetconf = (int **)malloc(sizeof(int*) * tetcount);
    mallocintarray(tetconf, tetcount);
    while (tetristr[y] != 0) //0 or '\0'
    {
        x = 0;
        i = 0;
        while (tetristr[y][i] != '\0')
        {
            if (tetristr[y][i] == '#')
            {
                tetconf[y][x++] = i - temp;
                temp = tetconf[y][0];
            }
            i++;
        }
        tetconfig[y] = ft_checkvalidtet(tetconfig[y]);
        if (tetconfig[y] == -1)
            return error; ////make an error message funtion maybe
        accomodatefigure(tetconf[y], temp);
        y++;
    }
    return (tetconf);
}