/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:20:07 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/04 16:36:33 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>

int main()
{
	uint16_t test = 19968;
	int i;
	int size;
	uint16_t flag = 32768;

	//uint16_t flag = 1;

	//set b1t
	//tetri |= 1 << 1 % 16;

	size = 16;
	i = 0;
	while (i < size)
	{
		if (test & flag)
			printf("1 ");
		else
			printf("0 ");
		if (i % 4  == 3)
			printf("\n");
		flag >>= 1;
		i++;
	}


	return (0);
}