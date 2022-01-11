/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:20:26 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/15 09:54:44 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)haystack;
	if (*needle == '\0')
		return (s);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == needle[j] && s[i + j] != '\0')
		{
			if (needle[j + 1] == '\0')
				return (&s[i]);
			j++;
		}
		i++;
	}
	return (0);
}
