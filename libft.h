/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:01:42 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/20 01:38:12 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <fcntl.h>

void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_error(void);
void				findbesttetris(int **tetconf, int tetcount);
int					placement(char *smallest_tetrissq, int *figure, int n, int i);
int					**determinefigures(char **tetristr, int tetcount);
int					**ft_figadjust(int **fig, int size, int tetcount);
int					ft_onetet(int *tet);
char				*squaresize(int	requiredsize);
#endif
