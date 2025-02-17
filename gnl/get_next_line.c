/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:04:13 by jnavalla          #+#    #+#             */
/*   Updated: 2025/02/16 18:38:22 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != 0)
	{
		counter++;
	}
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	result = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i] != 0)
	{
		result[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != 0)
	{
		result[j] = s2[i];
		i++;
		j++;
	}
	free((char *)s1);
	return (result);
}

t_gnl	*ft_new_node(int fd)
{
	t_gnl	*new;

	new = (t_gnl *)ft_calloc(1, sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->rest = NULL;
	return (new);
}

t_gnl	*ft_find_fd(t_gnl **file_list, int fd)
{
	t_gnl	*current;

	if (!file_list)
		return (NULL);
	if (!*file_list)
		*file_list = ft_new_node(fd);
	current = *file_list;
	while (current->next)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	if (current->fd == fd)
		return (current);
	current->next = ft_new_node(fd);
	return (current->next);
}

char	*get_next_line(int fd)
{
    static t_gnl	*file_list = NULL;
    t_gnl			*current;
    char			*result;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    current = ft_find_fd(&file_list, fd);
    if (!current)
        return (NULL);
    if (current->rest == NULL)
    {
        if (ft_read_buffer(current, fd) <= 0)
        {
            free(current); // libera pero no deja file list a null por lo que luego no crea un nuevo nodo 
			// y da mal, hay que hacer un ft que haga los free y que si quedan nodos los linkee y si no ponga file list a null
			file_list = NULL;
            return (NULL);
        }
    }
    result = (char *)ft_calloc(1, 1);
    if (!result)
        return (NULL);
    if (ft_build_result(&result, current))
        return (NULL);
    return (result);
}
// int main(void)
// {
//     int fd = open("input.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error abriendo el archivo");
//         return (1);
//     }

//     char *line;
//     while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }