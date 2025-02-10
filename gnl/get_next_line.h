#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>   // Para open() TESTS

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 22
# endif

typedef struct s_gnl
{
	int				fd;
	char			*rest;
	struct s_gnl	*next;
}	t_gnl;

char	*get_next_line(int fd);

#endif
