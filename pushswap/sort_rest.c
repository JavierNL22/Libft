/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:17:51 by jnavalla          #+#    #+#             */
/*   Updated: 2025/05/23 21:03:54 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a, t_stack *stack_b, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B
		|| to_sort->loc == TOP_B)
	{
		move_from_to(stack_a, stack_b, to_sort->loc, TOP_A);
		move_from_to(stack_a, stack_b, to_sort->loc, TOP_A);
	}
	if (to_sort->max_index == stack_a->top->index)
		sa(stack_a);
	to_sort->size -= 2;
}

void	sort_one(t_stack *stack_a, t_stack *stack_b, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B
		|| to_sort->loc == TOP_B)
		move_from_to(stack_a, stack_b, to_sort->loc, TOP_A);
	to_sort->size -= 1;
}
