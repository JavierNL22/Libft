/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:14:48 by jnavalla          #+#    #+#             */
/*   Updated: 2025/02/17 17:39:46 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	counter;

	counter = 0;
	if (size > 0)
	{
		while (counter < size - 1 && src[counter] != 0)
		{
			dst[counter] = src[counter];
			counter++;
		}
		dst[counter] = 0;
	}
	return (ft_strlen(src));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;
	size_t			counter;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > INT_MAX / size)
		return (NULL);
	result = (unsigned char *)malloc(nmemb * size);
	if (!result)
		return (NULL);
	counter = 0;
	while (counter < nmemb * size)
	{
		result[counter] = 0;
		counter++;
	}
	return (result);
}

ssize_t	ft_read_buffer(t_gnl *current, int fd)
{
	ssize_t	num_char;
	char	*temp;

	free(current->rest);
	current->rest = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!current->rest)
		return (-1);
	num_char = read(fd, current->rest, BUFFER_SIZE);
	if (num_char <= 0)
	{
		return (free(current->rest), current->rest = NULL, num_char);
	}
	if (num_char != BUFFER_SIZE)
	{
		temp = (char *)ft_calloc(num_char + 1, sizeof(char));
		if (!temp)
		{
			return (-1);
		}
		ft_strlcpy(temp, current->rest, num_char + 1);
		free(current->rest);
		current->rest = temp;
	}
	return (num_char);
}

ssize_t	ft_find_next_line(char **result, t_gnl *cur)
{
	ssize_t	i;
	char	*temp;

	i = -1;
	while (cur->rest[++i])
	{
		if (cur->rest[i] == '\n')
		{
			temp = (char *)ft_calloc(i + 2, sizeof(char));
			if (!temp)
				return (-1);
			ft_strlcpy(temp, cur->rest, i + 2);
			*result = ft_strjoin(*result, temp);
			free(temp);
			temp = ft_calloc(ft_strlen(cur->rest) - i, sizeof(char));
			if (!temp)
				return (-1);
			ft_strlcpy(temp, &cur->rest[i + 1], ft_strlen(cur->rest) - i);
			return (free(cur->rest), cur->rest = temp, i + 1);
		}
	}
	*result = ft_strjoin(*result, cur->rest);
	if (!*result)
		return (-1);
	return (free(cur->rest), cur->rest = NULL, 0);
}

int	ft_build_result(char **result, t_gnl *current)
{
	ssize_t	f_result;
	ssize_t	c_read;

	f_result = ft_find_next_line(result, current);
	while (f_result == 0)
	{
		c_read = ft_read_buffer(current, current->fd);
		if (c_read <= 0)
		{
			if (*result && **result && c_read == 0)
				return (0);
			free(*result);
			*result = NULL;
			return (free(current->rest), free(current), 1);
		}
		f_result = ft_find_next_line(result, current);
	}
	if (f_result == -1)
	{
		free(*result);
		*result = NULL;
		return (free(current->rest), free(current), 1);
	}
	return (0);
}
