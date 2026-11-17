NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = push_swap.c \
       parsing/ft_has_duplicate.c \
       parsing/ft_is_valid_number.c \
       parsing/parse_args.c \
       parsing/is_flag.c \
       parsing/parse_flag.c \
       parsing/parse_multi_flags.c \
       stack/ft_nodeadd_back.c \
       stack/ft_nodeclear.c \
       stack/ft_nodenew.c \
       stack/ft_print_stack.c \
       stack/stack_utils.c \
       stack/find_min_position.c \
       stack/find_max_position.c \
       operations/operations_helpers.c \
       operations/operations_push.c \
       operations/operations_reverse.c \
       operations/operations_rotate.c \
       operations/operations_swap.c \
       operations/op_counter.c \
       operations/put_op.c \
       operations/total_ops.c \
       sorting/simple_sort.c \
       sorting/medium_sort.c \
       sorting/radix_sort.c \
       sorting/sort_stack.c\
       sorting/adaptive_sort.c\
       sorting/compute_disorder.c\
       bench/print_bench.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
