/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:14:48 by jnavalla          #+#    #+#             */
/*   Updated: 2025/02/16 18:51:19 by jnavalla         ###   ########.fr       */
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

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > INT_MAX / size)
		return (NULL);
	result = (unsigned char *)malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_bzero (result, nmemb * size);
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	counter;
	char	*aux;

	aux = s;
	counter = 0;
	while (counter < n)
	{
		aux[counter] = 0;
		counter++;
	}
}

ssize_t ft_read_buffer(t_gnl *current, int fd)
{
    ssize_t num_char;
    char    *temp;

    free(current->rest);
    current->rest = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!current->rest)
        return (-1);
    num_char = read(fd, current->rest, BUFFER_SIZE);
    if (num_char <= 0)
    {
        free(current->rest);
        current->rest = NULL;
        return (-1);
    }
    if (num_char != BUFFER_SIZE)
    {
        temp = (char *)ft_calloc(num_char + 1, sizeof(char));
        if (!temp)
        {
            free(current->rest);
            current->rest = NULL;
            return (-1);
        }
        ft_strlcpy(temp, current->rest, num_char + 1);
        free(current->rest);
        current->rest = temp;
    }
    return (num_char);
}

size_t	ft_find_next_line(char **result, t_gnl *current)
{
    size_t	i;
    char	*temp;

    i = 0;
    while (current->rest[i])
    {
        if (current->rest[i] == '\n')
        {
            temp = (char *)ft_calloc(i + 2, sizeof(char));
            if (!temp)
                return (0);
            ft_strlcpy(temp, current->rest, i + 2);
            *result = ft_strjoin(*result, temp);
            free(temp);
            temp = (char *)ft_calloc(ft_strlen(current->rest) - i, sizeof(char));
            if (!temp)
                return (0);
            ft_strlcpy(temp, &current->rest[i + 1], ft_strlen(current->rest) - i);
            free(current->rest);
            current->rest = temp;
            return (i + 1);
        }
        i++;
    }
    *result = ft_strjoin(*result, current->rest);
    free(current->rest);
    current->rest = NULL;
    return (0);
}

int	ft_build_result(char **result, t_gnl *current)
{
    size_t	f_result;
    ssize_t	c_read;

    f_result = ft_find_next_line(result, current);
    while (f_result == 0)
    {
        c_read = ft_read_buffer(current, current->fd);
        if (c_read <= 0)
        {
            if (*result && **result)
                return (0);
            free(current->rest);
            free(current);
            free(*result);
            *result = NULL;
            return (1);
        }
        f_result = ft_find_next_line(result, current);
    }
    return (0);
}
