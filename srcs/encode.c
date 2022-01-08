/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:26 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/08 12:09:58 by willdonnell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"

//get top-leftmost placement of tetri string 16

void add_tetri(t_tetri *tetri, char *buf, int count)
{
	get_shape(buf, tetri, count);
	encode(buf, tetri, count);
}

void	get_shape(char *buf, t_tetri *tetri, int count)
{
	int	i;
	int	j;
	int x;

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
			{
				//ft_strcat(temp->rule, "d");
				tetri[count].stop += 4;
			}
				
			else if ((j - i) % 5 == 1)
			{
				//ft_strcat(temp->rule, "r");
				if (++x > tetri[count].right)
					(tetri[count].right)++;
			}
			else if ((j - i) % 5 == 3)
			{
				//ft_strcat(temp->rule, "2");
				tetri[count].stop += 4;
				x -= 2;
				if (x < tetri[count].left)
					tetri[count].left = x;
			}
			else if ((j - i) % 5 == 4)
			{
				//ft_strcat(temp->rule, "1");
				tetri[count].stop += 4;
				if (--x < tetri[count].left)
					tetri[count].left = x;
			}
			i = j;
		}
		j++;
	}
	tetri[count].stop += tetri[count].right;
	
}

void encode(char *buf, t_tetri *tetri, int index)
{
	uint64_t code = 0;
	
	int i;
	int count;
	uint64_t pow = 1;

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
