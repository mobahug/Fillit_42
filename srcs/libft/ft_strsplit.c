/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:16:16 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/24 12:41:27 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_word(char *word, char c, char **words, size_t i)
{
	char	*start;
	char	*result;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	result = ft_strdup(start);
	if (!result)
	{
		ft_free_words(words, i);
		return (NULL);
	}
	return (result);
}

static char	**ft_get_words(char *s, char c, size_t word_counter)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	words = (char **)malloc(sizeof(char *) * (word_counter + 1));
	if (!words)
		return (NULL);
	while (i < word_counter)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word = ft_get_word(s, c, words, i);
			if (word == NULL)
				return (NULL);
			words[i++] = word;
			s = s + (ft_strlen(word) + 1);
		}
	}
	words[i] = 0;
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*line;

	if (!s)
		return (0);
	line = ft_strdup((char *)s);
	if (!line)
		return (NULL);
	words = ft_get_words(line, c, ft_countwords(line, c));
	free(line);
	return (words);
}
