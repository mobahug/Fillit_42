/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 09:07:01 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/29 08:56:36 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i <= size)
		ptr[i++] = 0;
	return (ptr);
}
