/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:19:38 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/29 10:01:59 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (0);
	result = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!result)
		return (0);
	if (result)
	{
		ft_strcpy(result, s1);
		ft_strcat(result, s2);
	}
	return (result);
}
