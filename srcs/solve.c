/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:26:11 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/12 15:18:12 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"

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

int	get_size(int count)
{
	int	size;

	size = 2;
	while (size * size < count * 4)
		size++;
	return (size);
}

int	place_on_map(t_tetri *tetri, int size, uint16_t *map)
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
