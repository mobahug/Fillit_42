/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_bw.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:28:21 by willdonnell       #+#    #+#             */
/*   Updated: 2022/01/06 16:21:38 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 21

typedef struct s_tetri
{
	uint64_t		value;
	int				count;
	int				left;
	int				right;
	int				stop;
	struct s_tetri	*next;
}				t_tetri;

typedef struct s_queue
{
	struct s_tetri	*head;
	struct s_tetri	*tail;
}				t_queue;

void	get_shape(char buf[BUFF_SIZE], t_tetri *temp);
int	add_to_queue(char buf[BUFF_SIZE], t_queue *queue, int *count);

t_tetri	*readin(t_queue *queue, int *valid_count, int fd);
int		validate(char buf[BUFF_SIZE], t_queue *queue, int *valid_count);
int		check_connections(char buf[BUFF_SIZE], int i);

void	free_list(t_tetri *head);

#endif
