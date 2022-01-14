/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:20:59 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/14 12:17:46 by wdonnell         ###   ########.fr       */
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

/*
static void	color(t_tetri *tetri, char c)
{
	int	index;

	index = (int)(c - 'A');
	if (c == '.')
		ft_putcharcolor(c, "white");
	else if (tetri[index].code == 9223512776490647552ULL \
		|| tetri[index].code == 61440)
		ft_putcharcolor(c, "black");
	else if (tetri[index].code == 3221274624)
		ft_putcharcolor(c, "yellow");
	else if (tetri[index].code == 211108380049408 \
		|| tetri[index].code == 2147540992 \
		|| tetri[index].code == 70369817968640 \
		|| tetri[index].code == 3758104576)
		ft_putcharcolor(c, "cyan");
	else if (tetri[index].code == 211107306291200 \
		|| tetri[index].code == 3758129152 \
		|| tetri[index].code == 140739635888128 \
		|| tetri[index].code == 536928256)
		ft_putcharcolor(c, "magenta");
	else if (tetri[index].code == 1073799168\
		|| tetri[index].code == 70371965419520 \
		|| tetri[index].code == 3758112768 \
		|| tetri[index].code == 140740709613568)
		ft_putcharcolor(c, "blue");
	else if (tetri[index].code == 1610661888 \
		|| tetri[index].code == 140740709597184)
		ft_putcharcolor(c, "red");
	else if (tetri[index].code == 3221250048\
		|| tetri[index].code == 70371965435904 )
		ft_putcharcolor(c, "green");
}
*/

void	print_board(t_tetri *tetri, int size)
{
	char	*board;
	int		i;

	board = new_board(size);
	i = 0;
	while (tetri[i].code != 0)
	{
		add_to_board(&tetri[i], size, board);
		i++;
	}
	i = 0;
	while (i < size * size)
	{
		color(tetri, board[i]);
		if (i % size == size - 1)
			ft_putchar('\n');
		i++;
	}
	free (board);
}
