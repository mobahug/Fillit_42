/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_lenght.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:45:32 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/24 12:45:37 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number_lenght(long nb)
{
	int	counter;

	counter = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		counter++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		counter++;
	}
	return (counter);
}
