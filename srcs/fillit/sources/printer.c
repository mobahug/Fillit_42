/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:20:59 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/14 12:10:09 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Adds string representation of tetrimino to board.
** Shifted by its solution location.
*/

static void	add_to_board(t_tetri *tetri, int size, char *board)
{
	uint64_t	flag;
	int			i;
	int			count;

	count = tetri->pos;
	i = 0;
	flag = 1;
	flag <<= 15;
	while (i < 64)
	{
		if (i % 16 < size)
		{
			if (flag & tetri->code)
				board[count] = tetri->letter;
			count++;
		}
		if (i % 16 < 15)
			flag >>= 1;
		if (i % 16 == 15)
			flag <<= 31;
		i++;
	}
}

/*
** Create new "blank" board
*/

static char	*new_board(int size)
{
	char	*board;
	int		i;

	i = 0;
	board = ft_strnew((size_t)(size * size));
	while (i < (size * size))
		board[i++] = '.';
	board[i] = '\0';
	return (board);
}

/*
** Initilizes new board based on size of solution.
** Overlays string representation of each tetrimino in turn to board 
** Prints board.
*/

void	print_board(t_tetri *tetri, int size)
{
	char	*board;
	int		i;

	board = new_board(size);
	i = 0;
	while (tetri->code != 0)
	{
		add_to_board(tetri, size, board);
		tetri++;
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
