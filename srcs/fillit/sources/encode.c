/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:26 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/14 12:16:44 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Shifts tetrimino to its most "upper left" representation.
*/

static void	shift_shape(char *buf, char *shifted, t_tetri *tetri)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i] != '#')
		i++;
	j = i + tetri->left;
	i = 0;
	while (i < 19)
	{
		if (i % 5 != 4)
			shifted[i] = '.';
		else
			shifted[i] = '\n';
		i++;
	}
	shifted[i] = '\0';
	i = 0;
	while (buf[j])
	{
		if (buf[j] != '\n' && shifted[i] != '\n')
			shifted[i] = buf[j];
		i++;
		j++;
	}
}

/*
** With get_shape adds left, width and height data to tetrimino struct.
** Measured from origin '#' in string representaion.
*/

static void	sum_lwh(t_tetri *tetri, int j, int *i, int *x)
{
	if ((j - *i) % 5 == 0)
		tetri->height += 1;
	else if ((j - *i) % 5 == 1)
	{
		if (++(*x) > tetri->width)
			(tetri->width)++;
	}
	else if ((j - *i) % 5 == 3)
	{
		tetri->height += 1;
		*x -= 2;
		if (*x < tetri->left)
			tetri->left = *x;
	}
	else if ((j - *i) % 5 == 4)
	{
		tetri->height += 1;
		if (--(*x) < tetri->left)
			tetri->left = *x;
	}
	*i = j;
}

/*
** With sum_lwh adds left, width and height data to tetrimino struct.
** Measured from origin '#' in string representaion.
*/

static void	get_shape(char *buf, t_tetri *tetri)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	while (buf[i] != '#')
		i++;
	j = i + 1;
	x = 0;
	while (buf[j])
	{
		if (buf[j] == '#')
			sum_lwh(tetri, j, &i, &x);
		j++;
	}
	tetri->width += -tetri->left;
}

/*
** Encode string representation of tetrimino to a uint64_t representation.
*/

static void	encode(char *buf, t_tetri *tetri)
{
	uint64_t	code;
	uint64_t	pow;
	int			i;
	int			count;

	code = 0;
	pow = 1;
	i = 0;
	count = 3;
	while (i < 64)
	{
		if (i % 16 > 11)
		{
			if (buf[count] == '#')
				code += pow;
			if (count == 0 || count == 5 || count == 10)
				count += 9;
			count--;
		}
		pow *= 2;
		i++;
	}
	tetri->code = code;
}

/*
** Get shape specific data for each tetrimino.
*/

void	add_tetri(t_tetri *tetri, char *buf, int *count)
{
	char	shifted[21];

	tetri->left = 0;
	tetri->width = 0;
	tetri->height = 0;
	tetri->letter = 'A' + (char)*count;
	buf[20] = '\0';
	get_shape(buf, tetri);
	shift_shape(buf, shifted, tetri);
	encode(shifted, tetri);
}
