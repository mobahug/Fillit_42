/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:00:30 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/07 10:32:10 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "./libft/libft.h"
#define WIDTH_UINT16 16

/*
int	main()
{
	size_t	mask;
	int		len;
	char	*s;
	uint16_t	n = 0;

	len = WIDTH_UINT16 + (WIDTH_UINT16 / 4) - 1;
	s = ft_strnew(len);
	if (!s)
		return (NULL);
	mask = 0x8000; // 1000 0000 0000 0000
	len--;
	while (len >= 0)
	{
		if (len % 5 == 4)
			s[len--] = '\n';
		s[len--] = ((n & mask) > 0) + '0';
		mask >>= 1;
	}
	return (0);
}
*/

int	main()
{
	int	flag = 32768;
	int	i = 0;
	int	size = 32;
	int	value = 456456456;

	while (i < size)
	{
		if (flag & value) //looking for 1 bit
			printf("1");
		else
			printf("0");
		if (i % 4 == 3)














			printf("\n");
		flag >>= 1;
		i++;
	}
	return (0);
}
