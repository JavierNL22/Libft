NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= fractol.c
OBJS		= $(SRCS:.c=.o)

MLX_DIR		= ./minilibx-linux
MLX_INC		= -I$(MLX_DIR)
MLX_LIBS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(MLX_INC) $(OBJS) -o $(NAME) $(MLX_LIBS)

clean:
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
