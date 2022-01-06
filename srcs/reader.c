/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:35:00 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/06 13:39:35 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

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

int	validate(char *str, ssize_t ret)
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
		{
			return (0);
		}
		else if (i % 5 == 4 && str[i] != '\n')
		{
			return (0);
		}
		if (str[i] == '#' && ++hash_counter < 5)
		{
			total_connections += check_connection(str, i);
		}
		i++;
	}
	/*if (!(total_connections > 5 && hash_counter == 4))
	{
		printf("error12\n");
		return (0);
	}*/ // add the pieces if its valid
	return (1);
}

int	reader(char *str, int fd)
{
	char		buffer[BUFF_SIZE + 1];
	ssize_t		ret;

	ret = read(fd, &buffer, BUFF_SIZE);
	while (ret)
	{
		buffer[ret] = '\0';
		if (!(validate(buffer, ret)))
		{
			ft_putstr("error");
			exit(EXIT_FAILURE);
		}
		ret = read(fd, &buffer, BUFF_SIZE);
	}
	return(0);
}

int	main(int argc, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	if (argc != 2)
	{
		if (argc < 2)
		{
			ft_putstr("error");
			exit(EXIT_FAILURE);
		}
		if (argc > 2)
		{
			ft_putstr("error");
			exit(EXIT_FAILURE);
		}
	}
	if (reader(argv[1], fd) == 1)
		return (1);
	if (close(fd) == -1)
		return (1);
	return (0);
}
