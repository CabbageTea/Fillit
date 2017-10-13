/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findbesttetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 20:59:19 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/10 20:59:20 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tetris.h"

char    *squaresize(int requiredsize)
{
    char *sq;
    int sqsize;
    int newlinespots;

    newlinespots = requiredsize + 1;
    sqsize = (requiredsize ^ 2) + requiredsize + 1; //^2 the rows of characters, + requiredsize is the sum of the '\n' characters, + 1 for the ending '\0'
    sq = ft_memalloc(requiredsize);
    ft_memset(sq, '.', sqsize - 1);
    while (sq[newlinespots] != '\0')
    {
        sq[newlinespots] = '\n';
        newlinespots = newlinespots * 2;
        if (newlinespots > sqsize)
            break ;
    }
    return (sq);
}
void    empty_string(char *small_tetris_sq)
{
    int i;

    i = 0;
    while (small_tetris_sq[i] != '\0')
    {
        if (small_tetris_sq[i] != '.' || small_tetris_sq != '\n')
            small_tetris_sq[i] = '.';
        i++;
    }
}
int     fillit(char *small_tetris_sq, int *tetconf,)
{
    int ipos;

    ipos = ft_placement(small_tetris_sq, tetconf, size);
    if (ipos == -1)
        return (ipos);
}

int    recursive_backtrack(char *small_tetris_sq, int **tetconf, int size, int tetcount)
{
    int y;
    
    while (tetconf[y] < tetcount)
    {
        if (fillit(small_tetris_sq, tetconf[y], size) != -1))
        {
            size = squaresize(size + 1);
            empty_string(small_tetris_sq);
        }
        return (recursive_backtrack(small_tetris_sq, tetconf, --configs, size));
    }
    return (1);
}

char    *findbesttetris(int **tetconf, int tetcount)
{
    int     size;
    int     configs;
    char    *small_tetris_sq;
    t_point *trying;

    size = 3;
    trying.configs = tetcount ^ 2;
    configs = tetcount ^ 2;
    small_tetris_sq = squaresize(size);
    y = 0;
    recursive_backtrack(small_tetris_sq, tetconf, configs, size);
}