NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= fractol.c mandelbrot.c julia.c utils.c
OBJS		= $(SRCS:.c=.o)

MLX_DIR		= ./minilibx-linux
MLX_INC		= -I$(MLX_DIR)
MLX_LIBS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

PRINTF_DIR	= ./printf
PRINTF_LIB	= $(PRINTF_DIR)/libftprintf.a
PRINTF_INC	= -I$(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(MLX_INC) $(PRINTF_INC) $(OBJS) $(PRINTF_LIB) -o $(NAME) $(MLX_LIBS)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re