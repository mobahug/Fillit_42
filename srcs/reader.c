/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:35:00 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/03 15:24:54 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

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

int	ft_display_file(char *str)
{
	int		fd;
	char	buffer[BUFF_SIZE + 1];
	int		ret;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	ret = read(fd, &buffer, BUFF_SIZE);
	while (ret)
	{
		buffer[ret] = '\0';
		write(1, &buffer, ret);
		if (!valid(buffer, ret))
			return (0);
		else
			printf("Invalid!");
		ret = read(fd, &buffer, 1);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
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
	if (ft_display_file(argv[1]) == 1)
		return (1);
	return (0);
}
