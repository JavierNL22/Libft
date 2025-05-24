/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:15:42 by jnavalla          #+#    #+#             */
/*   Updated: 2025/05/23 21:01:01 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ordena un chunk de 3 elementos según su localización
void	sort_three(t_stack *stack_a, t_stack *stack_b, t_chunk *to_sort)
{
	int	max;

	max = to_sort->max_index;
	if (to_sort->loc == TOP_A)
		sort_three_top_a(stack_a, stack_b, to_sort, max);
	else if (to_sort->loc == BOTTOM_A)
		sort_three_bottom_a(stack_a, stack_b, to_sort, max);
	else if (to_sort->loc == TOP_B)
		sort_three_top_b(stack_a, stack_b, to_sort, max);
	else if (to_sort->loc == BOTTOM_B)
		sort_three_bottom_b(stack_a, stack_b, to_sort, max);
}

// Ordena 3 elementos en el top de stack_a
void	sort_three_top_a(t_stack *a, t_stack *b, t_chunk *to_sort, int max)
{
	if (a->top->index == max)
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
	}
	else if (a->top->next->index == max)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	to_sort->max_index -= 1;
	sort_two(a, b, to_sort);
}

// Ordena 3 elementos en el top de stack_b y los pasa a a
void	sort_three_top_b(t_stack *a, t_stack *b, t_chunk *to_sort, int max)
{
	pa(a, b);
	if (b->top->index == max)
	{
		pa(a, b);
		sa(a);
	}
	else if (b->top->next->index == max)
	{
		sb(b);
		pa(a, b);
		sa(a);
	}
	else
		pa(a, b);
	pa(a, b);
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	to_sort->max_index -= 1;
	sort_two(a, b, to_sort);
}

// Ordena 3 elementos en la parte de abajo de stack_a
void	sort_three_bottom_a(t_stack *a, t_stack *b, t_chunk *to_sort, int max)
{
	rra(a);
	rra(a);
	if (a->top->index == max)
	{
		sa(a);
		rra(a);
	}
	else if (a->top->next->index == max)
		rra(a);
	else
	{
		pb(a, b);
		rra(a);
		sa(a);
		pa(a, b);
	}
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	to_sort->max_index -= 1;
	sort_two(a, b, to_sort);
}

// Ordena 3 elementos en la parte de abajo de stack_b y los pasa a a
void	sort_three_bottom_b(t_stack *a, t_stack *b, t_chunk *to_sort, int max)
{
	rrb(b);
	rrb(b);
	if (b->top->index == max)
	{
		pa(a, b);
		rrb(b);
	}
	else if (b->top->next->index == max)
	{
		sb(b);
		pa(a, b);
		rrb(b);
	}
	else
	{
		rrb(b);
		pa(a, b);
	}
	to_sort->loc = TOP_B;
	to_sort->size -= 1;
	to_sort->max_index -= 1;
	sort_two(a, b, to_sort);
}
