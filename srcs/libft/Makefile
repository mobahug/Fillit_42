# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghorvath <ghorvath@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 08:40:43 by ghorvath          #+#    #+#              #
#    Updated: 2022/01/03 10:42:26 by ghorvath         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc	-Wall	-Wextra	-Werror
NAME	=	libft.a

SRCS	=	ft_atoi.c		ft_bzero.c		ft_isalnum.c	ft_isalpha.c	\
			ft_isascii.c	ft_isdigit.c	ft_isprint.c	ft_itoa.c		\
			ft_memalloc.c	ft_memccpy.c	ft_memchr.c		ft_memcmp.c		\
			ft_memcpy.c		ft_memdel.c		ft_memmove.c	ft_memset.c		\
			ft_putchar_fd.c	ft_putchar.c	ft_putendl_fd.c	ft_putendl.c	\
			ft_putnbr_fd.c	ft_putnbr.c		ft_putstr_fd.c	ft_putstr.c		\
			ft_strcat.c		ft_strchr.c		ft_strclr.c		ft_strcmp.c		\
			ft_strcpy.c		ft_strdel.c		ft_strdup.c		ft_strequ.c		\
			ft_striter.c	ft_striteri.c	ft_strjoin.c	ft_strlcat.c	\
			ft_strlen.c		ft_strmap.c		ft_strmapi.c	ft_strncat.c	\
			ft_strncmp.c	ft_strncpy.c	ft_strnequ.c	ft_strnew.c		\
			ft_strnstr.c	ft_strrchr.c	ft_strsplit.c	ft_strstr.c		\
			ft_strsub.c		ft_strtrim.c	ft_tolower.c	ft_toupper.c	\
			ft_isspace.c	ft_lstdel.c		ft_lstdelone.c	ft_countwords.c	\
			ft_free_words.c	ft_number_lenght.c	ft_lstadd.c	ft_lstiter.c	\
			ft_putstrcolor.c	ft_color.c	ft_putcharcolor.c	get_next_line.c	\

OBJECTS	=	ft_atoi.o		ft_bzero.o		ft_isalnum.o	ft_isalpha.o	\
			ft_isascii.o	ft_isdigit.o	ft_isprint.o	ft_itoa.o		\
			ft_memalloc.o	ft_memccpy.o	ft_memchr.o		ft_memcmp.o		\
			ft_memcpy.o		ft_memdel.o		ft_memmove.o	ft_memset.o		\
			ft_putchar_fd.o	ft_putchar.o	ft_putendl_fd.o	ft_putendl.o	\
			ft_putnbr_fd.o	ft_putnbr.o		ft_putstr_fd.o	ft_putstr.o		\
			ft_strcat.o		ft_strchr.o		ft_strclr.o		ft_strcmp.o		\
			ft_strcpy.o		ft_strdel.o		ft_strdup.o		ft_strequ.o		\
			ft_striter.o	ft_striteri.o	ft_strjoin.o	ft_strlcat.o	\
			ft_strlen.o		ft_strmap.o		ft_strmapi.o	ft_strncat.o	\
			ft_strncmp.o	ft_strncpy.o	ft_strnequ.o	ft_strnew.o		\
			ft_strnstr.o	ft_strrchr.o	ft_strsplit.o	ft_strstr.o		\
			ft_strsub.o		ft_strtrim.o	ft_tolower.o	ft_toupper.o	\
			ft_isspace.o	ft_lstdel.o		ft_lstdelone.o	ft_countwords.o	\
			ft_free_words.o	ft_number_lenght.o	ft_lstadd.o	ft_lstiter.o	\
			ft_putstrcolor.o	ft_color.o	ft_putcharcolor.o	get_next_line.o	\


HEADER	=	-c	-I	libft.h

all:	$(NAME)

$(NAME):
		$(CC)	-c	$(SRCS)	$(HEADER)
		ar		rc	$(NAME)	$(OBJECTS)

clean:
		/bin/rm	-f	$(OBJECTS)

fclean:
		make clean
		/bin/rm	-f	$(NAME)

re:		fclean	all
