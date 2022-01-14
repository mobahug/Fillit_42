/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:20:59 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/14 08:40:18 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**add_to_board function:
**
**Adding each tetrimino pieces to the board, which already transformed to
**alphabetical characters.
**Bitwise way we shifting each piece to the proper position.
**We also handling "bit reversal" aka mirroring error,
**what we had earlier, with shifting operators.
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
**new board function:
**
**Making the board, where we gonna place the tetrimino pieces.
**Initilaizing everything to 0 and fulfilling the empty board with '.'
**characters what will replace later each tetrimino.
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
**print_board:
**
**The function where we added the above functions into one
**to create and print out to the terminal the ready board
**properly, with colorized tetrimino letters.
**After it's done we freeing the memory, what we allocated
**to create the board, in order to avoid memory leaks.
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
