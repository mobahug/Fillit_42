/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:35:00 by ghorvath          #+#    #+#             */
/*   Updated: 2022/01/08 12:15:43 by willdonnell      ###   ########.fr       */
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

int	validate(char *str, t_tetri *tetri)
{
	int	i;
	int	hash_counter;
	int	total_connections;
	static int count = 0;

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
	{
		ft_putstrcolor("shape_wrong\n", "red");
			return (0);
	}
	else
	{
		ft_putstrcolor("shape_right\n", "green");
		if (count > 25)
			return (0);
		add_tetri(tetri, str, count);
		count++;
	}
	return (1);
}

int	reader(int fd, t_tetri *tetri)
{
	char		buffer[BUFF_SIZE + 1];
	ssize_t		ret;

	ret = read(fd, &buffer, BUFF_SIZE);
	while (ret)
	{
		if (ret == 21 && buffer[20] != '\n')
		{
			return (0);
		}
		printf("\n\n\n\n\n\n\n%s", buffer);
		printf("%d\n", BUFF_SIZE);
		buffer[ret] = '\0';
		if (!(validate(buffer, tetri))) //arr pointer
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


/*void add_to_arr(char *buf, int count)
{


	get_shape(buf);
	encode(buf);
}
*/
