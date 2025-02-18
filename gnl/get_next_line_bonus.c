/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:04:13 by jnavalla          #+#    #+#             */
/*   Updated: 2025/02/18 15:20:53 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != 0)
		counter++;
	return (counter);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	result = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!result)
		return (free((char *)s1), NULL);
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

t_gnl	*ft_find_fd(t_gnl **file_list, int fd)
{
	t_gnl	*current;

	if (!file_list)
		return (NULL);
	if (!*file_list)
	{
		*file_list = (t_gnl *)ft_calloc(1, sizeof(t_gnl));
		if (!*file_list)
			return (NULL);
		(*file_list)->fd = fd;
		return (*file_list);
	}
	current = *file_list;
	while (current->next && current->fd != fd)
		current = current->next;
	if (current->fd == fd)
		return (current);
	current->next = (t_gnl *)ft_calloc(1, sizeof(t_gnl));
	if (!current->next)
		return (NULL);
	current->next->fd = fd;
	return (current->next);
}

void	ft_free_node(t_gnl **file_list, t_gnl *node)
{
	t_gnl	*current;
	t_gnl	*prev;

	if (!file_list || !*file_list || !node)
		return ;
	if (*file_list == node)
		*file_list = node->next;
	else
	{
		current = *file_list;
		while (current && current != node)
		{
			prev = current;
			current = current->next;
		}
		if (current == node)
			prev->next = current->next;
	}
	free(node->rest);
	free(node);
	if (!*file_list)
		*file_list = NULL;
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
			ft_free_node(&file_list, current);
			return (NULL);
		}
	}
	result = (char *)ft_calloc(1, 1);
	if (!result)
		return (ft_free_node(&file_list, current), NULL);
	if (ft_build_result(&result, current))
		return (ft_free_node(&file_list, current), NULL);
	if (!result)
		return (ft_free_node(&file_list, current), result);
	return (result);
}
