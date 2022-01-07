/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:36:03 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/18 12:36:42 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	counter;
	size_t	i;
	char	*str;

	counter = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (ft_isspace(s[counter]))
		counter++;
	if (counter == ft_strlen(s))
		return ("\0");
	len = ft_strlen(s) - 1;
	while (ft_isspace(s[len]))
		len--;
	len += 1;
	str = (char *)malloc(sizeof(char) * (len - counter) + 1);
	if (!str)
		return (NULL);
	while (counter < len)
		str[i++] = s[counter++];
	str[i] = '\0';
	return (str);
}
