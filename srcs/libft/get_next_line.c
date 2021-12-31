/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:26:10 by ghorvath          #+#    #+#             */
/*   Updated: 2021/12/21 14:58:37 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(char **string, char **line)
{
	int		lenght;
	char	*tracker;

	lenght = 0;
	while ((*string)[lenght] != '\n' && (*string)[lenght] != '\0')
		lenght++;
	if ((*string)[lenght] == '\n')
	{
		*line = ft_strsub(*string, 0, lenght);
		tracker = ft_strdup(&((*string)[lenght + 1]));
		free(*string);
		*string = tracker;
		if ((*string)[0] == '\0')
			ft_strdel(string);
	}
	else
	{
		*line = ft_strdup(*string);
		ft_strdel(string);
	}
	return (1);
}

static int	error_handling(char **string, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && string[fd] == NULL)
		return (0);
	else
		return (get_line(&string[fd], line));
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*string[FD_SIZE];
	char		buffer[BUFF_SIZE + 1];
	char		*tracker;

	if (fd < 0 || line == NULL)
		return (-1);
	while (1)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret <= 0)
			break ;
		buffer[ret] = '\0';
		if (string[fd] == NULL)
			string[fd] = ft_strdup(buffer);
		else
		{
			tracker = ft_strjoin(string[fd], buffer);
			free(string[fd]);
			string[fd] = tracker;
		}
		if (ft_strchr(string[fd], '\n'))
			break ;
	}
	return (error_handling(string, line, ret, fd));
}
