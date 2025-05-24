/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:56:57 by jnavalla          #+#    #+#             */
/*   Updated: 2025/05/24 12:56:21 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum e_loc
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}	t_loc;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_chunk
{
	int		min_index;
	int		max_index;
	int		size;
	t_loc	loc;
}	t_chunk;

// =================== utils.c ===================
t_node	*create_node(int value);
void	append_node(t_node **stack, t_node *new);
int		belongs_to_chunk(t_node *node, t_chunk *chunk);
long	ft_atol(const char *str);
int		is_int_arg(const char *str);

// =================== utils_2.c ===================
void	free_stack(t_stack *stack);
int		init_stack(t_stack *a, int argc, char **argv);
void	free_args(char **args);
int		count_split(char **split);
int		handle_error(t_stack *a, char **args);

// =================== args.c ===================
int		is_valid_input(int argc, char **argv);
int		has_duplicates(t_stack *stack);
int		merge_args(char ***args, char **split_args, int *total_args);
int		join_args_loop(int argc, char **argv, char ***args, int *total_args);
int		copy_args(char **dst, char **src, int k);

// =================== move.c ===================
int		move_from_to(t_stack *stack_a, t_stack *stack_b, t_loc from, t_loc to);
void	move_from_top_a(t_stack *stack_a, t_stack *stack_b, t_loc to);
void	move_from_top_b(t_stack *stack_a, t_stack *stack_b, t_loc to);
void	move_from_bottom_a(t_stack *stack_a, t_stack *stack_b, t_loc to);
void	move_from_bottom_b(t_stack *stack_a, t_stack *stack_b, t_loc to);

// =================== options/*.c ===================
void	swap(t_stack *stack);
void	push(t_stack *src, t_stack *dest);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// =================== split.c ===================
void	split_c_to_stacks(t_stack *a, t_stack *b, t_chunk c, t_chunk **sub_c);
void	split_from_top_a(t_stack *a, t_stack *b, t_chunk c, t_chunk **sub_c);
void	split_from_bottom_a(t_stack *a, t_stack *b, t_chunk c, t_chunk **sub_c);
void	split_from_top_b(t_stack *a, t_stack *b, t_chunk c, t_chunk **sub_c);
void	split_from_bottom_b(t_stack *a, t_stack *b, t_chunk c, t_chunk **sub_c);

// =================== sort_rest.c ===================
void	sort_two(t_stack *stack_a, t_stack *stack_b, t_chunk *to_sort);
void	sort_one(t_stack *stack_a, t_stack *stack_b, t_chunk *to_sort);

// =================== sort_three.c ===================
void	sort_three(t_stack *a, t_stack *b, t_chunk *to_sort);
void	sort_three_top_a(t_stack *a, t_stack *b, t_chunk *to_sort, int max);
void	sort_three_top_b(t_stack *a, t_stack *b, t_chunk *to_sort, int max);
void	sort_three_bottom_a(t_stack *a, t_stack *b, t_chunk *to_sort, int max);
void	sort_three_bottom_b(t_stack *a, t_stack *b, t_chunk *to_sort, int max);

// =================== mini_sorts.c ===================
void	sort(t_stack *a, t_stack *b, t_chunk chunk);
int		is_sorted(t_stack *stack);
void	sort_three_a(t_stack *a);
void	sort_five_a(t_stack *a, t_stack *b);

// =================== push_swap.c ===================
void	sort_chunks(t_stack *stack_a, t_stack *stack_b, t_chunk chunk);
void	init_vars(t_stack *a, t_stack *b, char ***args, int *t_args);
int		check_stack(t_stack *stack_a, char **args, int total_args);

// =================== index.c ===================
int		stack_size(t_node *stack);
void	bubble_sort(int *arr, int size);
void	assign_indexes_loop(t_node *stack, int *values, int size);
void	assign_indexes(t_node *stack);

#endif