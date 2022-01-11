# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 12:35:34 by ghorvath          #+#    #+#              #
#    Updated: 2022/01/11 09:47:39 by ghorvath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
CC			=	clang
CFLAGS		=	-Wall	-Wextra	-Werror	-I	includes	-I	libft/includes
SRCS		=	encode.c	main.c	printer.c	reader.c	solve.c
SRCS_DIR	=	./sources/
OBJS_DIR	=	./objects/
OBJS		=	$(addprefix	$(OBJS_DIR), $(SRCS:.c=.o))
LIBFLAGS	=	-Llibft
LIB			=	-lft

all:	$(NAME)

$(NAME):	$(OBJS)

	$(CC)	$(CFLAGS)	$(OBJS)	-o	$(NAME)	$(LIBFLAGS)	$(LIB)


$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c

	make	-sC	libft
	mkdir	-p	$(OBJS_DIR)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@


clean:
	rm	-rf	$(OBJS_DIR)
	rm	-f	libft/*.o


fclean:	clean
	rm	-f	$(NAME)
	rm	-f	libft/libft.a

re:	fclean all

.PHONY:	all	clean	fclean	re