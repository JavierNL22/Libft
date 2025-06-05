/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:29:18 by jnavalla          #+#    #+#             */
/*   Updated: 2025/06/04 23:51:30 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(int argc, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		if (!args[i][j])
			return (0);
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		if (!is_int_arg(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*checker;

	current = stack->top;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}

int	merge_args(char ***args, char **split_args, int *total_args)
{
	int		j;
	char	**new_args;

	j = count_split(split_args);
	*total_args += j;
	new_args = malloc(sizeof(char *) * (*total_args + 1));
	if (!new_args)
	{
		if (*args)
			free_args(*args);
		return (1);
	}
	j = 0;
	if (*args)
	{
		while ((*args)[j])
		{
			new_args[j] = (*args)[j];
			j++;
		}
	}
	if (*args)
		free(*args);
	j = copy_args(new_args, split_args, j);
	return (new_args[j] = NULL, *args = new_args, 0);
}

int	join_args_loop(int argc, char **argv, char ***args, int *total_args)
{
	int		i;
	char	**split_args;

	i = 1;
	*args = NULL;
	*total_args = 0;
	while (i < argc)
	{
		split_args = ft_split(argv[i], ' ');
		if (!split_args || !split_args[0])
		{
			if (split_args)
				free_args(split_args);
			return (0);
		}
		if (merge_args(args, split_args, total_args))
			return (0);
		free(split_args);
		i++;
	}
	return (1);
}

int	copy_args(char **dst, char **src, int k)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dst[k] = src[i];
		k++;
		i++;
	}
	return (k);
}
