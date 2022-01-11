/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 08:54:45 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/18 12:35:46 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char	(*f)(char))
{
	int		i;
	char	*str;

	if (s == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s == 0 || str == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
