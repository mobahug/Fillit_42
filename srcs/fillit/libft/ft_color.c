/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:28:21 by ghorvath          #+#    #+#             */
/*   Updated: 2021/12/16 15:28:24 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_color(char *s)
{
	if (!ft_strcmp(s, "red"))
		ft_putstr(RED);
	if (!ft_strcmp(s, "normal"))
		ft_putstr(NORMAL);
	if (!ft_strcmp(s, "green"))
		ft_putstr(GREEN);
	if (!ft_strcmp(s, "yellow"))
		ft_putstr(YELLOW);
	if (!ft_strcmp(s, "blue"))
		ft_putstr(BLUE);
	if (!ft_strcmp(s, "magenta"))
		ft_putstr(MAGENTA);
	if (!ft_strcmp(s, "cyan"))
		ft_putstr(CYAN);
	if (!ft_strcmp(s, "white"))
		ft_putstr(WHITE);
}
