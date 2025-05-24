/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:22:41 by jnavalla          #+#    #+#             */
/*   Updated: 2025/05/22 17:55:54 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *a, t_stack *b, t_chunk chunk)
{
	if (a->size <= 1 || is_sorted(a))
		return ;
	else if (a->size == 3)
		sort_three_a(a);
	else if (a->size == 5)
		sort_five_a(a, b);
	else
		sort_chunks(a, b, chunk);
}

void	sort_three_a(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && third > second && first > third)
		ra(a);
	else if (second > first && second > third && first > third)
		rra(a);
	else if (second > first && second > third && third > first)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && second > third && first > third)
	{
		sa(a);
		rra(a);
	}
}

void	sort_five_a(t_stack *a, t_stack *b)
{
	int	i;

	i = 5;
	while (i > 3)
	{
		if (a->top->index == 0 || a->top->index == 1)
		{
			pb(a, b);
			i--;
		}
		else
			ra(a);
	}
	if (b->top->index < b->top->next->index)
		sb(b);
	sort_three_a(a);
	pa(a, b);
	pa(a, b);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}
