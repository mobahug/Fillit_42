/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:52:54 by ghorvath          #+#    #+#             */
/*   Updated: 2021/11/24 15:06:07 by ghorvath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void	(*f)(t_list *elem))
{
	if (lst)
	{
		while (lst)
		{
			(*f)(lst);
			lst = lst->next;
		}
	}
}
