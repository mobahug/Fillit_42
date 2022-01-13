# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 12:35:34 by ghorvath          #+#    #+#              #
#    Updated: 2022/01/13 14:40:58 by ghorvath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit
NAME_COLOR	=	fillit_color
CC			=	clang
CFLAGS		=	-Wall	-Wextra	-Werror
SRCS		=	encode.c	main.c	printer.c	reader.c	solve.c
SRCS_DIR	=	./sources/
SRCS_COLOR	=	encode.c	main.c	color.c	reader.c	solve.c
OBJS_DIR	=	./objects/
OBJS		=	$(addprefix	$(OBJS_DIR), $(SRCS:.c=.o))
OBJS_COLOR		=	$(addprefix	$(OBJS_DIR), $(SRCS_COLOR:.c=.o))
LIBFLAGS	=	-L libft
LIB			=	-lft
INCLUDES	=	-I	includes	-I	libft/includes

all:	$(NAME)

$(NAME):	$(OBJS)
	echo $(OBJS)
	$(CC)	$(CFLAGS)	$(INCLUDES)	$(OBJS)	-o	$(NAME)	$(LIBFLAGS)	$(LIB)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c

	make	-sC	libft
	mkdir	-p	$(OBJS_DIR)
	$(CC)	$(CFLAGS)	$(INCLUDES)	-c	$<	-o	$@

color:	$(NAME_COLOR)

$(NAME_COLOR):	$(OBJS_COLOR)

	$(CC)	$(CFLAGS)	$(INCLUDES)	$(OBJS_COLOR)	-o	$(NAME)	$(LIBFLAGS)	$(LIB)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c

	make	-sC	libft
	mkdir	-p	$(OBJS_DIR)
	$(CC)	$(CFLAGS)	$(INCLUDES)	-c	$<	-o	$@

clean:
	rm	-rf	$(OBJS_DIR)
	rm	-f	libft/*.o


fclean:	clean
	rm	-f	$(NAME)
	rm	-f	libft/libft.a

re:	fclean all

.PHONY:	all	clean	fclean	re