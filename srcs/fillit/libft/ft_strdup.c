/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:38:46 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/15 09:44:59 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*newletter;

	i = 0;
	newletter = 0;
	newletter = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (newletter == 0)
		return (0);
	while (s1[i])
	{
		newletter[i] = s1[i];
		i++;
	}
	newletter[i] = '\0';
	return (newletter);
}
