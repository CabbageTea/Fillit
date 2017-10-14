/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 20:06:11 by dmontoya          #+#    #+#             */
/*   Updated: 2017/10/14 16:30:40 by dmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		TETRIS_H
# define	TETRIS_H

int		ft_placement(char *sqstr, int *figure, int n);
int		**determinefigures(char **tetrisstr, int tetcount);
char	*findbesttetris(int **tetconf, int tetcount);

#endif
