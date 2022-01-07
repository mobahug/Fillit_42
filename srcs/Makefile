<<<<<<< HEAD
NAME = tester
CC = gcc
FLAGS = -Wall -Wextra -Werror
MORE_FLAGS = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
#SRCS = old_main.c encode.c readin_old.c
#OBJS = old_main.o encode.o readin_old.o
SRCS = test_main.c
OBJS = test_main.o
HDRS = fillit_bw.h#
LIB = libft/

all:
#	$(MAKE) -C $(LIB)
=======
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 12:35:34 by ghorvath          #+#    #+#              #
#    Updated: 2022/01/07 13:45:03 by ghorvath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester
CC = gcc
FLAGS = -Wall -Wextra -Werror
MORE_FLAGS = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
SRCS = main.c reader.c
OBJS = main.o reader.o
HDRS = fillit_bw.h
LIB = libft/

all:
	$(MAKE) -C $(LIB)
>>>>>>> Polishing
	$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -L ./libft -lft -o $(NAME)

$(OBJS) : $(SRCS)
<<<<<<< HEAD
#	$(CC) $(FLAGS) $(MORE_FLAGS) -c $(SRCS) -I $(HDRS)
	$(CC) $(FLAGS) -c $(SRCS) -I $(HDRS)
=======
	$(CC) $(FLAGS) $(MORE_FLAGS) -c $(SRCS) -I $(HDRS)
#	$(CC) $(FLAGS) -c $(SRCS) -I $(HDRS)
>>>>>>> Polishing



clean:
	rm -f $(OBJS)
<<<<<<< HEAD
#	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
#	$(MAKE) -C $(LIB) fclean
=======
	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIB) fclean
>>>>>>> Polishing

re: fclean all

.PHONY: all clean fclean re