/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:05:49 by jnavalla          #+#    #+#             */
/*   Updated: 2025/02/18 15:21:36 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl
{
	int				fd;
	char			*rest;
	struct s_gnl	*next;
}	t_gnl;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
t_gnl	*ft_new_node(int fd);
t_gnl	*ft_find_fd(t_gnl **file_list, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
ssize_t	ft_read_buffer(t_gnl *current, int fd);
int		ft_build_result(char **result, t_gnl *current);
ssize_t	ft_find_next_line(char **result, t_gnl *current);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free_node(t_gnl **file_list, t_gnl *node);

#endif
