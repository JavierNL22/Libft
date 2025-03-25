CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libftprintf.a
SRCS	= ft_printf.c
OBJS	= ${SRCS:.c=.o}
RM		= rm -rf
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) ${NAME}

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} $(LIBFT)
	ar -rc $@ ${OBJS}
	ar -rc $@ $(LIBFT_DIR)/*.o

clean:
	${RM} ${OBJS}
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:	clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY:	all clean fclean re