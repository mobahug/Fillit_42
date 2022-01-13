/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:20:59 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/13 15:26:06 by wdonnell         ###   ########.fr       */
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

static void	color(char c)
{
	if ((c - 'A') % 7 == 0)
		ft_putcharcolor(c, "red");
	else if ((c - 'A') % 7 == 1)
		ft_putcharcolor(c, "green");
	else if ((c - 'A') % 7 == 2)
		ft_putcharcolor(c, "yellow");
	else if ((c - 'A') % 7 == 3)
		ft_putcharcolor(c, "blue");
	else if ((c - 'A') % 7 == 4)
		ft_putcharcolor(c, "magenta");
	else if ((c - 'A') % 7 == 5)
		ft_putcharcolor(c, "cyan");
	else if ((c - 'A') % 7 == 6)
		ft_putcharcolor(c, "black");
	else
		ft_putcharcolor(c, "white");
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
		color(board[i]);
		if (i % size == size - 1)
			ft_putchar('\n');
		i++;
	}
	free (board);
}
