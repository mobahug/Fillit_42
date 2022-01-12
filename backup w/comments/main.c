/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:43:01 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/12 11:12:48 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"

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
		ft_putstrcolor("error\n", "red");
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
		ft_putstrcolor("error\n", "red");
		return (0);
	}
	tetri[count].code = 0;
	size = solve(tetri, count, map);
	print_board(tetri, size, count);
	close(fd);
	return (0);
}

/*
static void print_map(uint16_t map[16])
{
	int i = 0;
	int j = 0;
	uint16_t flag = 32768;

	while (i < 16)
	{
		j = 0;
		while (j < 16)
		{
			if (map[i] & flag)
				printf("1 ");
			else
				printf("0 ");
			flag >>= 1;
			j++;
		}
		flag = 32768;
		printf("\n");
		i++;
	}
}



	int i = 0;
	while (i < 4)
	{
		print_tetri(tetri[i++].code);
		printf("\n");
	}
	*/
