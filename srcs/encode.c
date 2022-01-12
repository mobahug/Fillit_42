/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:26 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/12 13:12:02 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"

void	add_tetri(t_tetri *tetri, char *buf, int count)
{
	char	shifted[21];

	tetri[count].left = 0;
	tetri[count].width = 0;
	tetri[count].height = 0;
	tetri[count].letter = 'A' + (char)count;
	get_shape(buf, tetri, count);
	shift_shape(buf, shifted, tetri, count);
	encode(shifted, tetri, count);
}

void	shift_shape(char *buf, char *shifted, t_tetri *tetri, int count)
{
	int	i;
	int	j;

	buf[20] = '\0';
	i = 0;
	while (buf[i] != '#')
		i++;
	j = i + tetri[count].left;
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

void	get_shape(char *buf, t_tetri *tetri, int count)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	i = 0;
	while (buf[i] != '#')
		i++;
	j = i + 1;
	while (buf[j])
	{
		if (buf[j] == '#')
		{
			if ((j - i) % 5 == 0)
				tetri[count].height += 1;
			else if ((j - i) % 5 == 1)
				if (++x > tetri[count].width)
					(tetri[count].width)++;
			else if ((j - i) % 5 == 3)
			{
				tetri[count].height += 1;
				x -= 2;
				if (x < tetri[count].left)
					tetri[count].left = x;
			}
			else if ((j - i) % 5 == 4)
			{
				tetri[count].height += 1;
				if (--x < tetri[count].left)
					tetri[count].left = x;
			}
			i = j;
		}
		j++;
	}
	tetri[count].width += -tetri[count].left;
}

void	encode(char *buf, t_tetri *tetri, int index)
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
	tetri[index].code = code;
}
