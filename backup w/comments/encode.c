/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:26 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/11 17:14:09 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"
#include <stdio.h>

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

	//printf("left: %d\n", tetri[*count].left);
	//printf("right: %d\n", tetri[*count].right);
	//printf("height: %d\n", tetri[*count].height);
	buf[20] = '\0';
	i = 0;
	while (buf[i] != '#') //get index of first # in buf
		i++;
	j = i + tetri[count].left;
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
	/*
	i = 0;
	printf("SHIFTED:\n");
	while (i < 19)
		printf("%c", shifted[i++]);
	printf("\n");
	*/
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
			{
				//"d"
				tetri[count].height += 1;
			}
			else if ((j - i) % 5 == 1)
			{
				//"r"
				if (++x > tetri[count].width)
					(tetri[count].width)++;
			}
			else if ((j - i) % 5 == 3)
			{
				//"2"
				tetri[count].height += 1;
				x -= 2;
				if (x < tetri[count].left)
					tetri[count].left = x;
			}
			else if ((j - i) % 5 == 4)
			{
				//"1"
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

/*
WORKING
static void	shift_shape(char *buf, char *shifted, t_tetri *tetri, int count)
{
	int	i;
	int	j;

	buf[20] = '\0';
	i = 0;
	while (buf[i] != '#')
		i++;
	j = i + tetri[count].left;
	i = 0;
	while (buf[j])
	{
		if (buf[j] != '\n')
		{
			shifted[i] = buf[j];
			i++;
			j++;
		}
		else
			j++;
	}
}

static void	get_shape(char *buf, t_tetri *tetri, int count)
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
			{
				if (++x > tetri[count].width)
					(tetri[count].width)++;
			}
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


static void get_left(char *buf, t_tetri *tetri, int count)
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
			if ((j - i) % 5 == 1)
				x++;
			if ((j - i) % 5 == 3)
			{
				x -= 2;
				if (x < tetri[count].left)
					tetri[count].left = x;
			}
			else if ((j - i) % 5 == 4)
			{
				if (--x < tetri[count].left)
					tetri[count].left = x;
			}
			i = j;
		}
		j++;
	}
}

static void get_height_width(char *shifted, t_tetri *tetri, int count)
{
	int	i;
	int	j;
	int	x;
	
	x = 0;
	i = -tetri[count].left;
	//printf("i: %d\n", i);
	j = i + 1;
	while (shifted[j])
	{
		if (shifted[j] == '#')
		{
			if ((j - i) % 4 == 0)
				tetri[count].height++;
			else if ((j - i) % 4 == 1)
			{
				if (++x > tetri[count].width)
					(tetri[count].width)++;
			}
			else if ((j - i) % 4 == 2)
				tetri[count].height++;
			else if ((j - i) % 4 == 3)
				tetri[count].height++;
			i = j;
		}
		j++;
	}
	tetri[count].width += -tetri[count].left;
}

static void	encode(char *shifted, t_tetri *tetri, int index)
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
			if (shifted[count] == '#')
				code += pow;
			if (count == 0 || count == 5 || count == 10)
				count += 9;
			//if (count == 0 || count == 4 || count == 8)
				//count += 8;
			count--;
		}
		pow *= 2;
		i++;
	}
	tetri[index].code = code;
}

void	add_tetri(t_tetri *tetri, char *buf, int count)
{
	char	*shifted;

	tetri[count].left = 0;
	tetri[count].width = 0;
	tetri[count].height = 0;
	tetri[count].letter = 'A' + (char)count;
	shifted = new_board(4);
	//get_left(buf, tetri, count);
	get_shape(buf, tetri, count);
	shift_shape(buf, shifted, tetri, count);
	//get_height_width(shifted, tetri, count);
	encode(shifted, tetri, count);
	
	printf("tetri[%d]:\n", count);
	printf("left: %d\n", tetri[count].left);
	printf("width: %d\n", tetri[count].width);
	printf("height: %d\n", tetri[count].height);
	printf("\n");
	
	printf("SHIFTED:\n");
	int i = 0;
	while (shifted[i])
	{
		printf("%c", shifted[i]);
		if (i % 4 == 3)
			printf("\n");
		i++;
	}
	printf("\n");
	
	free (shifted);
}
*/
