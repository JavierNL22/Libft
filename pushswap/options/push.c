/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:10:02 by jnavalla          #+#    #+#             */
/*   Updated: 2025/05/22 18:14:39 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node	*node;

	if (!src || !src->top)
		return ;
	node = src->top;
	src->top = node->next;
	if (!src->top)
		src->bottom = NULL;
	node->next = dest->top;
	dest->top = node;
	if (!dest->bottom)
		dest->bottom = node;
	src->size--;
	dest->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pb\n");
}
