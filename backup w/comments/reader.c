/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:35:00 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/11 11:14:35 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "fillit_bw.h"

int	check_connection(char *str, int i)
{
	int	connections;

	connections = 0;
	while (i < 19)
	{
		if (i >= 1 && str[i - 1] == '#')
		{
			connections++;
		}
		if (i < 19 && str[i + 1] == '#')
		{
			connections++;
		}
		if(i >= 5 && str[i - 5] == '#')
		{
			connections++;
		}
		if (i < 15 && str[i + 5] == '#')
		{
			connections++;
		}
		i++;
	}
	return(connections);
}

int	validate(char *str, t_tetri *tetri, int *count)
{
	int	i;
	int	hash_counter;
	int	total_connections;

	hash_counter = 0;
	total_connections = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 != 4 && (str[i] != '#' && str[i] != '.'))
			return (0);
		else if (i % 5 == 4 && str[i] != '\n')
			return (0);
		if (str[i] == '#' && ++hash_counter < 5)
			total_connections += check_connection(str, i);
		i++;
	}
	if (total_connections < 6 && hash_counter != 4)
		return (0);
	else
	{
		//ft_putstrcolor("shape_right\n", "green");
		if (*count > 25)
			return (0);
		add_tetri(tetri, str, count);
		(*count)++;
	}
	return (1);
}

int	reader(int fd, t_tetri *tetri, int *count)
{
	char		buffer[BUFF_SIZE + 1];
	ssize_t		ret;

	ret = read(fd, &buffer, BUFF_SIZE);
	while (ret)
	{
		if (ret == 21 && buffer[20] != '\n')
			return (0);
		buffer[ret] = '\0';
		if (!(validate(buffer, tetri, count))) //arr pointer
			return (0);
		ret = read(fd, &buffer, BUFF_SIZE);
	}
	return(1);
}
