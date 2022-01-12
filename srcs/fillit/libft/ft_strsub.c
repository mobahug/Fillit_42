/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 08:21:39 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/29 08:20:48 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_string;
	size_t	i;

	i = 0;
	sub_string = (char *)malloc(sizeof(char) * (len + 1));
	if (s == 0 || sub_string == 0)
		return (0);
	if (start > len)
		return (sub_string);
	while (i < len && s[start] != '\0')
	{
		sub_string[i] = s[start];
		start++;
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}
