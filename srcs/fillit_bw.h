/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_bw.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willdonnelly <willdonnelly@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:28:21 by willdonnell       #+#    #+#             */
/*   Updated: 2022/01/08 11:31:12 by willdonnell      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdint.h>

# define BUFF_SIZE 21

typedef struct s_tetri
{
	uint64_t		code;
	int				count;
	int				left;
	int				right;
	int				stop;
}				t_tetri;

int	check_connection(char *str, int i);
int	validate(char *str, t_tetri *tetri);
int	reader(int fd, t_tetri *tetri);

void add_tetri(t_tetri *tetri, char *buf, int count);
void encode(char *buf, t_tetri *tetri, int index);
void	get_shape(char *buf, t_tetri *tetri, int count);


#endif
