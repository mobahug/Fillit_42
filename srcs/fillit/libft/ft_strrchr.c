/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:14:33 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/15 14:10:43 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	int		lenght;

	lenght = ft_strlen(s);
	s1 = (char *)s;
	while (lenght >= 0)
	{
		if (s1[lenght] == c)
			return (&(s1[lenght]));
		lenght--;
	}
	return (0);
}
