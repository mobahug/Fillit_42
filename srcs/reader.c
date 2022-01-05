/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:35:00 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/05 15:50:06 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

/*
int	valid(char *str, int ret)
{
	int		i = 4;
	int		j = 1;


	while (j < 5)
	{

		while (i < 21 * j)
		{

			if (str[i] != '\n' && str[i] != '\0')
			{
				printf("%d%c", i, str[i]);
				return (1);
			}
			i += 5;
		}
		j++;
		i += 1;
	}
	return (0);
}
*/

int	check_connection(char *str)
{
	int	connections;
	int	i;

	i = 0;
	connections = 0;
	while (i < 19)
	{
		if (i == '#')
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
		}
		printf("(%d)index\n", i);
		printf("(%d)connections\n\n", connections);
		i++;
	}
	printf("(%d)here\n", i);
	if (connections == 6 || connections == 8)
	{
		printf("%dsecond here\n", connections);
		return (1);
	}
	ft_putstr("error\n");
	return(0);
}

int	validate(char *str, ssize_t ret)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 != 4 && (i == '#' || i == '.'))
		{
			//printf("first");
			return (0);
		}
		else if (i % 5 == 4 && (i == '\n' || i == '\0'))
		{
			//printf("second");
			return (0);
		}
		i++;
	}
	if (!(check_connection(str)))
	{
		//printf("error12\n");
		return (0);
	}
	return (1);
}

int	ft_display_file(char *str, int fd)
{
	char		buffer[BUFF_SIZE + 1];
	ssize_t		ret;

	ret = read(fd, &buffer, BUFF_SIZE);
	while (ret)
	{
		buffer[ret] = '\0';
		//write(1, &buffer, ret);
		if (validate(buffer, ret))
		{
			printf("success\n");
			return (1);
		}
		else
		{
			printf("Invalid!\n");
			return (0);
		}
		ret = read(fd, &buffer, 1);
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
	if (ft_display_file(argv[1], fd) == 1)
		return (1);
	if (close(fd) == -1)
		return (1);
	return (0);
}
