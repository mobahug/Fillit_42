/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:43:01 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/13 13:10:13 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	error(char *str)
{
	ft_putendl(str);
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int			fd;
	int			count;
	int			size;
	t_tetri		tetri[27];
	uint16_t	map[16];

	if (argc != 2)
		error("usage: ./fillit file.fillit");
	fd = open(argv[1], O_RDONLY);
	count = 0;
	if (!reader(fd, tetri, &count))
		error("error");
	tetri[count].code = 0;
	size = solve(tetri, count, map);
	print_board(tetri, size);
	close(fd);
	return (0);
}
