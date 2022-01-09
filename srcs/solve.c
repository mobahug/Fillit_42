/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:26:11 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/09 16:02:22 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"
#include <stdio.h>


void	solve(t_tetri *tetri, int *count, uint16_t *map)
{
	int	size;
	printf(" total count:\t%d\n", *count);
	
	size = get_size(count);
	//size = 4;
	ft_bzero(map, sizeof(uint16_t) * 16);
	//place_on_map(tetri, &size, 0, map, count);
	
	while (!place_on_map(tetri, &size, 0, map, count))
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	printf("size:\t%d\n", size);
	
	
}

int	get_size(int *count)
{
	int	size;

	size = 2;
	while (size * size < *count * 4)
		size++;
	return (size);
}

int place_on_map(t_tetri *tetri, int *size, int index, uint16_t *map, int *count)
{
	int	x;
	int	y;

	if (index == *count)
		return (1);
	y = 0;
	while (tetri[index].height + y < *size)
	{
		x = 0;
		while (tetri[index].right + x < *size)
		{
			if (!(*(uint64_t *)(map + y) & tetri[index].code >> x)) //is possible to add
			{
				*(uint64_t *)(map + y) ^= (tetri[index].code >> x); //add piece to map
				if (place_on_map(tetri, size, index + 1, map, count)) //recurse
					return (1);
				*(uint64_t *)(map + y) ^= (tetri[index].code >> x); //delete current tetri (if recurse fail)
			}
			x++;
		}
		y++;
	}
	return (0);
}
