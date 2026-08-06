NAME		= push_swap
CC			= cc
# CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR 	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		= main.c compression.c complex.c disorder.c lis.c input.c medium_sort.c \
push_buckets.c push_buckets_util.c push.c rotate.c simple_sort.c swap.c stack.c
OBJS		= $(SRCS:.c=.o)
HEADER		= push_swap.h

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
