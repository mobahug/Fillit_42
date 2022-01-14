/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:28:21 by willdonnell       #+#    #+#             */
/*   Updated: 2022/01/14 13:12:23 by wdonnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"
# include <stdint.h>

# define BUFF_SIZE 21

typedef struct s_tetri
{
	uint64_t		code;
	int				pos;
	char			letter;
	int				left;
	int				width;
	int				height;
}				t_tetri;

int		reader(int fd, t_tetri *tetri, int *count);
void	add_tetri(t_tetri *tetri, char *buf, int *count);
int		solve(t_tetri *tetri, int count, uint16_t *map);
void	print_board(t_tetri *tetri, int size);

#endif
