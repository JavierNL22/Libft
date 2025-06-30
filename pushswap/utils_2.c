/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:33:08 by jnavalla          #+#    #+#             */
/*   Updated: 2025/06/30 11:06:29 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	current = stack->top;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	stack->top = NULL;
}

int	init_stack(t_stack *a, int argc, char **argv)
{
	int		i;
	t_node	*new_node;

	i = 0;
	while (i < argc)
	{
		new_node = create_node(ft_atoi(argv[i]));
		if (!new_node)
		{
			free_stack(a);
			return (0);
		}
		append_node(&a->top, new_node);
		a->size++;
		i++;
	}
	a->bottom = a->top;
	if (a->bottom)
		while (a->bottom->next)
			a->bottom = a->bottom->next;
	return (1);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	count_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		i++;
	return (i);
}

int	handle_error(t_stack *a, char **args)
{
	ft_putstr_fd("Error\n", 2);
	if (a)
		free_stack(a);
	if (args)
		free_args(args);
	return (1);
}
