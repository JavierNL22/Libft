CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g #quitar el -g!!!!!!!!!!!!
NAME    = push_swap
PRINTF_DIR = ./ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
SRCS = push_swap.c utils.c utils_2.c args.c index.c move.c sort_three.c sort_rest.c split.c mini_sorts.c \
    ./options/push.c ./options/swap.c ./options/rotate.c ./options/r_rotate.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) -o $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re