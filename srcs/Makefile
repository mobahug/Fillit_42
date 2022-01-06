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
	$(MAKE) $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -L ./libft -lft -o $(NAME)

$(OBJS) : $(SRCS)
#	$(CC) $(FLAGS) $(MORE_FLAGS) -c $(SRCS) -I $(HDRS)
	$(CC) $(FLAGS) -c $(SRCS) -I $(HDRS)



clean:
	rm -f $(OBJS)
#	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -f $(NAME)
#	$(MAKE) -C $(LIB) fclean

re: fclean all

.PHONY: all clean fclean re