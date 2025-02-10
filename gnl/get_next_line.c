#include "get_next_line.h"

t_gnl	*find_fd(t_gnl **file_list, int fd)
{
	t_gnl	*current;
	t_gnl	*new;

	if (!file_list)
		return (NULL);
	current = *file_list;
	while (current->next)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	if (current->fd == fd)
			return (current);
	new = (t_gnl *)malloc(sizeof(t_gnl));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->rest = NULL;
	if (*file_list == NULL)
	{
		*file_list = new;
		return (new);
	}
	current->next = new;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_gnl	*file_list = NULL;
	struct t_gnl		*current;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = find_fd(&file_list, fd);
	if (!current)
		return (NULL);
}
