NAME	=	push_swap

SRCS	=	exit_handle.c init.c push_swap.c push_op.c rev_op.c \
			ro_op.c sort_small.c sort_big.c sort_utils.c sort_utils2.c \
			stack_utils.c stack_utils2.c sw_op.c

OBJS	=	$(SRCS:.c=.o)
CC		=	cc 
CFLAG	=	-Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
		make -sC libft

$(NAME): $(OBJS)
		$(CC) $(CFLAG) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c push_swap.h
		$(CC) $(CFLAG) -c $< -o $@

clean: 
		rm -rf $(OBJS)
		make -C libft fclean

fclean: clean
		rm -rf $(NAME)
		make -C libft fclean

re: fclean all

.PHONY: all clean fclean re