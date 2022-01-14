/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:26:11 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/14 13:03:21 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Finds minimum starting size based on number of tetriminos
*/

static int	get_size(int count)
{
	int	size;

	size = 2;
	while (size * size < count * 4)
		size++;
	return (size);
}

/*
** Attempts to find solution given size.
** Saves final position of each "solved" tetrimino reletive to size.
*/

static int	place_on_map(t_tetri *tetri, int size, uint16_t *map)
{
	int	x;
	int	y;

	if (tetri->code == 0)
		return (1);
	y = 0;
	while (tetri->height + y < size)
	{
		x = 0;
		while (tetri->width + x < size)
		{
			if (!(*(uint64_t *)(map + y) & tetri->code >> x))
			{
				*(uint64_t *)(map + y) ^= (tetri->code >> x);
				tetri->pos = x + (y * size);
				if (place_on_map(tetri + 1, size, map))
					return (1);
				*(uint64_t *)(map + y) ^= (tetri->code >> x);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Updates size untill solution is found
*/

int	solve(t_tetri *tetri, int count, uint16_t *map)
{
	int	size;

	size = get_size(count);
	ft_bzero(map, sizeof(uint16_t) * 16);
	while (!place_on_map(&tetri[0], size, map))
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	return (size);
}
