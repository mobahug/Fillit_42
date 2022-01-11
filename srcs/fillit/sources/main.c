/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:43:01 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/11 10:21:07 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print_map(uint16_t map[16])
{
	int			i;
	int			j;
	uint16_t	flag;

	i = 0;
	j = 0;
	flag = 32768;
	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			if (map[i] & flag)
				ft_putstrcolor("1 ", "red");
			else
				ft_putstrcolor("0 ", "green");
			flag >>= 1;
			j++;
		}
		flag = 32768;
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	int			count;
	int			size;
	t_tetri		tetri[26];
	uint16_t	map[16];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstrcolor("error!\n", "red");
		return (0);
	}
	if (argc != 2)
	{
		ft_putstrcolor("usage: ./fillit file.fillit\n", "red");
		return (0);
	}
	count = 0;
	if (!reader(fd, tetri, &count))
	{
		ft_putstrcolor("error!\n", "red");
		return (0);
	}
	print_tetri(tetri, 0);
	ft_putchar('\n');
	size = solve(tetri, count, map);
	print_map(map);
	ft_putchar('\n');
	print_board(tetri, size, count);
	close(fd);
	return (0);
}
