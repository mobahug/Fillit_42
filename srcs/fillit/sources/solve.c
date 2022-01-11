/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:26:11 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/11 10:08:05 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve(t_tetri *tetri, int count, uint16_t *map)
{
	int	size;

	size = get_size(count);
	ft_bzero(map, sizeof(uint16_t) * 16);
	while (!place_on_map(tetri, size, 0, map, count))
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	return (size);
}

int	get_size(int count)
{
	int	size;

	size = 2;
	while (size * size < count * 4)
		size++;
	return (size);
}

int	place_on_map(t_tetri *tetri, int size, int index, uint16_t *map, int count)
{
	int	x;
	int	y;

	if (index == count)
		return (1);
	y = 0;
	while (tetri[index].height + y < size)
	{
		x = 0;
		while (tetri[index].width + x < size)
		{
			if (!(*(uint64_t *)(map + y) & tetri[index].code >> x))
			{
				*(uint64_t *)(map + y) ^= (tetri[index].code >> x);
				tetri[index].pos = x + (y * size);
				if (place_on_map(tetri, size, index + 1, map, count))
					return (1);
				*(uint64_t *)(map + y) ^= (tetri[index].code >> x);
			}
			x++;
		}
		y++;
	}
	return (0);
}
