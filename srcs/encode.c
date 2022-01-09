/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:26 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/09 16:02:04 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"
#include <stdio.h>

//get top-leftmost placement of tetri string 16

void add_tetri(t_tetri *tetri, char *buf, int *count)
{
	char shifted[21];


	printf("count:\t%d\n", *count);
	tetri[*count].left = 0;
	tetri[*count].right = 0;
	tetri[*count].height = 0;
	get_shape(buf, tetri, count);
	shift_shape(buf, shifted, tetri, count);
	encode(shifted, tetri, count);
}

void shift_shape(char *buf, char *shifted, t_tetri *tetri, int *count)
{
	int i;
	int j;
	
	printf("left: %d\n", tetri[*count].left);
	printf("right: %d\n", tetri[*count].right);
	printf("height: %d\n", tetri[*count].height);
	buf[20] = '\0';
	i = 0;
	while(buf[i] != '#') //get index of first # in buf
		i++;
	j = i + tetri[*count].left;
	//init new blank map (use this later??)
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
	i = 0;
	printf("SHIFTED:\n");
	while (i < 19)
		printf("%c", shifted[i++]);
	printf("\n");
	
}

void	get_shape(char *buf, t_tetri *tetri, int *count)
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
				tetri[*count].height += 1;
			}
				
			else if ((j - i) % 5 == 1)
			{
				//ft_strcat(temp->rule, "r");
				if (++x > tetri[*count].right)
					(tetri[*count].right)++;
			}
			else if ((j - i) % 5 == 3)
			{
				//ft_strcat(temp->rule, "2");
				tetri[*count].height += 1;
				x -= 2;
				if (x < tetri[*count].left)
					tetri[*count].left = x;
			}
			else if ((j - i) % 5 == 4)
			{
				//ft_strcat(temp->rule, "1");
				tetri[*count].height += 1;
				if (--x < tetri[*count].left)
					tetri[*count].left = x;
			}
			i = j;
		}
		j++;
	}
}

void encode(char *buf, t_tetri *tetri, int *index)
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
	tetri[*index].code = code;
}
