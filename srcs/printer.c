/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:20:59 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/10 22:43:04 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"
#include <stdio.h>

void print_tetri(t_tetri *tetri, int index)
{
	uint64_t flag = 1;
	int i;

	i = 0;
	flag  <<= 15;
	while (i < 64)
	{
		if (i % 16 == 15)
			flag <<= 31;
		if (flag & tetri[index].code)
			printf("1 ");
		else
			printf("0 ");
		flag >>= 1;
		if (i % 16 == 15)
			printf("\n");
		i++;
		
	}
}

void add_to_board(t_tetri *tetri, int index, int size, char *board)
{
	uint64_t flag = 1;
	int i;
	int count;

	count = tetri[index].pos;
	i = 0;
	flag  <<= 15;
	while (i < 64)
	{
		if (i % 16 == 15)
			flag <<= 32;
		if (i % 16 < size)
		{
			if (flag & tetri[index].code)
				board[count] = tetri[index].letter;
			printf("count: %d\n", count);
			count++;
		}
		flag >>= 1;
		i++;
	}
}

void print_board(t_tetri *tetri, int size, int count)
{
	char	*board;
	int		i;

	board = new_board(size);
	i = 0;
	while (i < count)
	{
		add_to_board(tetri, i, size, board);
		i++;
	}
	i = 0;
	while (i < size * size)
	{
		ft_putchar(board[i]);
		if (i % size == size - 1)
			ft_putchar('\n');
		i++;
	}
	free (board);
}

char *new_board(int size)
{
	char *board;
	int	i;

	i = 0;
	board =	ft_strnew((size_t)(size * size));
	while (i < (size * size))
		board[i++] = '.';
	board[i] = '\0';
	return (board);
}
