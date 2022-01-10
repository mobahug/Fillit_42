# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdonnell <wdonnell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 12:35:34 by ghorvath          #+#    #+#              #
#    Updated: 2022/01/10 18:34:16 by wdonnell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror
MORE_FLAGS = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
SRCS = main.c reader.c encode.c solve.c printer.c
OBJS = main.o reader.o encode.o solve.o printer.o
HDRS = fillit_bw.h
LIB = libft/

all:
	$(MAKE) -C $(LIB)
	$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -L ./libft -lft -o $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(FLAGS) $(MORE_FLAGS) -c $(SRCS) -I $(HDRS)
#	$(CC) $(FLAGS) -c $(SRCS) -I $(HDRS)



clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB) fclean

re: fclean all

.PHONY: all clean fclean re