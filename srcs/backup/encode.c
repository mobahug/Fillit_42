/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:26 by wdonnell          #+#    #+#             */
/*   Updated: 2022/01/06 16:24:07 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_bw.h"

//get top-leftmost placement of tetri string 16

int	add_to_queue(char buf[BUFF_SIZE], t_queue *queue, int *count)
{
	t_tetri	*temp;

	temp = (t_tetri *)malloc(sizeof(t_tetri));
	if (!temp)
		return (0);
	
	temp->right = 0;
	temp->left = 0;
	temp->stop = 0;
	get_shape(buf, temp);
	temp->count = *count;
	temp->next = NULL;
	if (queue->tail == NULL)
	{
		queue->tail = temp;
		queue->head = temp;
	}
	else
	{
		(queue->tail)->next = temp;
		queue->tail = temp;
	}
	return (1);
}
void	get_shape(char buf[BUFF_SIZE], t_tetri *temp)
{
	int	i;
	int	j;
	int x;

	x = 0;
	i = 0;
	while (buf[i] != '#')
		i++;
	j = i + 1;
	while (buf[j])
	{
		if (buf[j] == '#')
		{
			if ((j - i) % 5 == 0)
			{
				//ft_strcat(temp->rule, "d");
				temp->stop += 4;
			}
				
			else if ((j - i) % 5 == 1)
			{
				//ft_strcat(temp->rule, "r");
				if (++x > temp->right)
					(temp->right)++;
			}
			else if ((j - i) % 5 == 3)
			{
				//ft_strcat(temp->rule, "2");
				temp->stop += 4;
				x -= 2;
				if (x < temp->left)
					temp->left = x;
			}
			else if ((j - i) % 5 == 4)
			{
				//ft_strcat(temp->rule, "1");
				temp->stop += 4;
				if (--x < temp->left)
					temp->left = x;
			}
			i = j;
		}
		j++;
	}
	temp->stop += temp->right;
	
}

