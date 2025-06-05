/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:11:13 by jnavalla          #+#    #+#             */
/*   Updated: 2025/06/04 23:52:14 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

//"Swaps" the biggest to the end of the array, then the second biggest, etc.
void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	assign_indexes_loop(t_node *stack, int *values, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == values[i])
			{
				stack->index = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	assign_indexes(t_node *stack)
{
	int		size;
	int		*values;
	t_node	*tmp;
	int		i;

	size = stack_size(stack);
	values = malloc(sizeof(int) * size);
	if (!values)
		return ;
	tmp = stack;
	i = 0;
	while (i < size)
	{
		values[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(values, size);
	assign_indexes_loop(stack, values, size);
	free(values);
}
