/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:33:38 by jnavalla          #+#    #+#             */
/*   Updated: 2025/06/04 23:53:23 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_subchunks(t_chunk chunk, t_chunk *chunk0,
	t_chunk *chunk1, t_chunk *chunk2)
{
	int	chunk_size;
	int	third;

	chunk_size = chunk.max_index - chunk.min_index + 1;
	third = chunk_size / 3;
	chunk0->min_index = chunk.min_index;
	chunk0->max_index = chunk.min_index + third - 1;
	chunk0->size = chunk0->max_index - chunk0->min_index + 1;
	chunk0->loc = chunk.loc;
	chunk1->min_index = chunk.min_index + third;
	chunk1->max_index = chunk.min_index + 2 * third - 1;
	chunk1->size = chunk1->max_index - chunk1->min_index + 1;
	chunk1->loc = chunk.loc;
	chunk2->min_index = chunk.min_index + 2 * third;
	chunk2->max_index = chunk.max_index;
	chunk2->size = chunk2->max_index - chunk2->min_index + 1;
	chunk2->loc = chunk.loc;
}

//Recursive function to sort the chunks, chunk 0 = low, 1 = mid, 2 = high
void	sort_chunks(t_stack *stack_a, t_stack *stack_b, t_chunk chunk)
{
	t_chunk	chunk0;
	t_chunk	chunk1;
	t_chunk	chunk2;
	t_chunk	*new_chunks[3];

	if (chunk.max_index < chunk.min_index)
		return ;
	if (chunk.max_index - chunk.min_index <= 2)
	{
		if (chunk.max_index - chunk.min_index == 2)
			sort_three(stack_a, stack_b, &chunk);
		else if (chunk.max_index - chunk.min_index == 1)
			sort_two(stack_a, stack_b, &chunk);
		else if (chunk.max_index - chunk.min_index == 0)
			sort_one(stack_a, stack_b, &chunk);
		return ;
	}
	create_subchunks(chunk, &chunk0, &chunk1, &chunk2);
	new_chunks[0] = &chunk0;
	new_chunks[1] = &chunk1;
	new_chunks[2] = &chunk2;
	split_c_to_stacks(stack_a, stack_b, chunk, new_chunks);
	sort_chunks(stack_a, stack_b, *new_chunks[2]);
	sort_chunks(stack_a, stack_b, *new_chunks[1]);
	sort_chunks(stack_a, stack_b, *new_chunks[0]);
}

void	init_vars(t_stack *stack_a, t_stack *stack_b, char ***args, int *t_args)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_a->size = 0;
	stack_b->top = NULL;
	stack_b->bottom = NULL;
	stack_b->size = 0;
	*args = NULL;
	*t_args = 0;
}

int	check_stack(t_stack *stack_a, char **args, int total_args)
{
	if (!is_valid_input(total_args, args))
		return (handle_error(NULL, args));
	if (!init_stack(stack_a, total_args, args))
		return (handle_error(NULL, args));
	if (has_duplicates(stack_a))
		return (handle_error(stack_a, args));
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	**args;
	int		total_args;
	t_chunk	full_chunk;

	init_vars(&stack_a, &stack_b, &args, &total_args);
	if (argc < 2 || (argc == 2 && (!argv[1][0] || argv[1][0] == ' ')))
		return (0);
	if (!join_args_loop(argc, argv, &args, &total_args))
		return (handle_error(NULL, args));
	if (check_stack(&stack_a, args, total_args))
		return (1);
	assign_indexes(stack_a.top);
	full_chunk.min_index = 0;
	full_chunk.max_index = stack_a.size - 1;
	full_chunk.size = stack_a.size;
	full_chunk.loc = TOP_A;
	sort(&stack_a, &stack_b, full_chunk);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (args)
		free_args(args);
	return (0);
}
