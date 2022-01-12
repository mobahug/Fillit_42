/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:20:59 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/12 16:23:24 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if (board[i] == 'A' || board[i] == 'I' || board[i] == 'Q' || board[i] == 'Y')
			ft_putcharcolor(board[i], "red");
		else if (board[i] == 'B' || board[i] == 'J' || board[i] == 'R' || board[i] == 'Z')
			ft_putcharcolor(board[i], "green");
		else if (board[i] == 'C' || board[i] == 'K' || board[i] == 'S')
			ft_putcharcolor(board[i], "magenta");
		else if (board[i] == 'D' || board[i] == 'L' || board[i] == 'T')
			ft_putcharcolor(board[i], "yellow");
		else if (board[i] == 'E' || board[i] == 'M' || board[i] == 'U')
			ft_putcharcolor(board[i], "blue");
		else if (board[i] == 'F' || board[i] == 'N' || board[i] == 'V')
			ft_putcharcolor(board[i], "cyan");
		else if (board[i] == 'G' || board[i] == 'O' || board[i] == 'W')
			ft_putcharcolor(board[i], "normal");
		else if (board[i] == 'H' || board[i] == 'P' || board[i] == 'X')
			ft_putcharcolor(board[i], "white");
		else
			ft_putchar(board[i]);
		if (i % size == size - 1)
			ft_putchar('\n');
		i++;
	}
	free (board);
}
