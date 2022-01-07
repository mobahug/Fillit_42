/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:43:01 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/07 13:44:02 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_tetri tetri[26];

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
	if (!reader(fd, tetri))
	{
		ft_putstrcolor("error!\n", "red");
		return (1);
	}
	//solve(tetri[]);
	//print(tetri[]);
	close(fd);
	return (0);
}
