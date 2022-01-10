/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_bw.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:28:21 by willdonnell       #+#    #+#             */
/*   Updated: 2022/01/10 22:06:41 by wdonnell         ###   ########.fr       */
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
	int				pos;
	char			letter;
	int				left;
	int				width;
	int				height;
}				t_tetri;

int	check_connection(char *str, int i);
int	validate(char *str, t_tetri *tetri, int *count);
int	reader(int fd, t_tetri *tetri, int *count);

void add_tetri(t_tetri *tetri, char *buf, int *count);
void encode(char *buf, t_tetri *tetri, int *index);
void	get_shape(char *buf, t_tetri *tetri, int *count);
void shift_shape(char *buf, char *shifted, t_tetri *tetri, int *count);

int		solve(t_tetri *tetri, int count, uint16_t *map);
int		get_size(int count);
int		place_on_map(t_tetri *tetri, int size, int index, uint16_t *map, int count);

char *new_board(int size);
void add_to_board(t_tetri *tetri, int index, int size, char *board);
void print_board(t_tetri *tetri, int size, int count);
void print_tetri(t_tetri *tetri, int index);

#endif
