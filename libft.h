/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dglaser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 21:01:42 by dglaser           #+#    #+#             */
/*   Updated: 2017/10/22 19:05:31 by dglaser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_error(void);
void				findbesttetris(int **tetconf, int tetcount);
int					placement(char *stsq, int *figure, int n, int i);
int					**determinefigures(char **tetristr, int tetcount);
int					**ft_figadjust(int **fig, int size, int tetcount);
char				*squaresize(int requiredsize);
int					ft_determinesize(char *grid);
int					**ft_tetconfiguration(char **ts, int **t, int y, int h);
int					**two_tets(int **tetconf, int tetcount);

#endif
