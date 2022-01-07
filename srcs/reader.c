/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:35:00 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/07 09:50:45 by ghorvath         ###   ########.fr       */
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
			printf("\n(%d)first_pass\n", i);
			return (0);
		}
		else if (i % 5 == 4 && str[i] != '\n')
		{
			printf("\n(%d)second_pass\n", i);
			return (0);
		}
		if (str[i] == '#' && ++hash_counter < 5)
		{
			printf("\n(%d)third_pass\n", i);
			total_connections += check_connection(str, i);
			printf("(%d)\n", i);
		}
		i++;
	}
	if ((total_connections != 6 || total_connections != 8) && hash_counter != 4)
	{
		ft_putstrcolor("shape_wrong\n", "red");
			return (0);
	} // add the pieces if its valid
	else
		ft_putstrcolor("shape_right\n", "green");
	return (1);
}

int	reader(char *str, int fd)
{
	char		buffer[BUFF_SIZE + 1];
	ssize_t		ret;

	ret = read(fd, &buffer, BUFF_SIZE);
	while (ret)
	{
		printf("\n\n\n\n\n\n\n%s", buffer);
		printf("%d\n", BUFF_SIZE);
		buffer[ret] = '\0';
		if (!(validate(buffer, ret)))
		{
			return (0);
			//ft_putstrcolor("Invalid!\n", "red");
		}
		//else
			//ft_putstrcolor("Valid!\n", "green");
		ret = read(fd, &buffer, BUFF_SIZE);
	}
	return(1);
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
			ft_putstrcolor("error!\n", "red");
			exit(EXIT_FAILURE);
		}
		if (argc > 2)
		{
			ft_putstrcolor("error!\n", "red");
			exit(EXIT_FAILURE);
		}
	}
	if (reader(argv[1], fd))
	{
		ft_putstrcolor("Sucess!\n", "green");
		return (0);
	}
	else
	{
		ft_putstrcolor("error!\n", "red");
		return (1);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}
