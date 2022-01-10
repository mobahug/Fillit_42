/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:43:01 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/10 13:42:50 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"
#include <stdio.h>

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
	//printf("\n");
}

int	main(int argc, char **argv)
{
	int			fd;
	int			count;
	t_tetri		tetri[26];
	uint16_t	map[16];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	if (argc != 2) //add usage
	{
		if (argc != 2)
		{
			ft_putstrcolor("usage: ./fillit file.fillit\n", "red");
			exit(EXIT_FAILURE);
		}
	}
	count = 0;
	if (!reader(fd, tetri, &count))
	{
		ft_putstrcolor("error!\n", "red");
		return (0);
	}
	
	solve(tetri, count, map);
	print_map(map);
	//print(tetri[]);
	close(fd);
	return (0);
}

