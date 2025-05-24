/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:05:15 by jnavalla          #+#    #+#             */
/*   Updated: 2025/05/24 13:00:33 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_c_to_stacks(t_stack *a, t_stack *b, t_chunk c, t_chunk **new_c)
{
	if (c.loc == TOP_A)
		split_from_top_a(a, b, c, new_c);
	else if (c.loc == BOTTOM_A)
		split_from_bottom_a(a, b, c, new_c);
	else if (c.loc == TOP_B)
		split_from_top_b(a, b, c, new_c);
	else if (c.loc == BOTTOM_B)
		split_from_bottom_b(a, b, c, new_c);
}

void	split_from_top_a(t_stack *a, t_stack *b, t_chunk c, t_chunk **new_c)
{
	int	i;

	i = 0;
	while (i < c.size)
	{
		if (belongs_to_chunk(a->top, new_c[2]))
			move_from_to(a, b, TOP_A, BOTTOM_A);
		else if (belongs_to_chunk(a->top, new_c[1]))
			move_from_to(a, b, TOP_A, TOP_B);
		else if (belongs_to_chunk(a->top, new_c[0]))
			move_from_to(a, b, TOP_A, BOTTOM_B);
		i++;
	}
	new_c[0]->loc = BOTTOM_B;
	new_c[1]->loc = TOP_B;
	new_c[2]->loc = BOTTOM_A;
}

void	split_from_bottom_a(t_stack *a, t_stack *b, t_chunk c, t_chunk **new_c)
{
	int	i;

	i = 0;
	while (i < c.size)
	{
		if (belongs_to_chunk(a->bottom, new_c[2]))
			move_from_to(a, b, BOTTOM_A, TOP_A);
		else if (belongs_to_chunk(a->bottom, new_c[1]))
			move_from_to(a, b, BOTTOM_A, TOP_B);
		else if (belongs_to_chunk(a->bottom, new_c[0]))
			move_from_to(a, b, BOTTOM_A, BOTTOM_B);
		i++;
	}
	new_c[0]->loc = BOTTOM_B;
	new_c[1]->loc = TOP_B;
	new_c[2]->loc = TOP_A;
}

void	split_from_top_b(t_stack *a, t_stack *b, t_chunk c, t_chunk **new_c)
{
	int	i;

	i = 0;
	while (i < c.size)
	{
		if (belongs_to_chunk(b->top, new_c[2]))
			move_from_to(a, b, TOP_B, TOP_A);
		else if (belongs_to_chunk(b->top, new_c[1]))
			move_from_to(a, b, TOP_B, BOTTOM_A);
		else if (belongs_to_chunk(b->top, new_c[0]))
			move_from_to(a, b, TOP_B, BOTTOM_B);
		i++;
	}
	new_c[0]->loc = BOTTOM_B;
	new_c[1]->loc = BOTTOM_A;
	new_c[2]->loc = TOP_A;
}

void	split_from_bottom_b(t_stack *a, t_stack *b, t_chunk c, t_chunk **new_c)
{
	int	i;

	i = 0;
	while (i < c.size)
	{
		if (belongs_to_chunk(b->bottom, new_c[2]))
			move_from_to(a, b, BOTTOM_B, TOP_A);
		else if (belongs_to_chunk(b->bottom, new_c[1]))
			move_from_to(a, b, BOTTOM_B, BOTTOM_A);
		else if (belongs_to_chunk(b->bottom, new_c[0]))
			move_from_to(a, b, BOTTOM_B, TOP_B);
		i++;
	}
	new_c[0]->loc = TOP_B;
	new_c[1]->loc = BOTTOM_A;
	new_c[2]->loc = TOP_A;
}
