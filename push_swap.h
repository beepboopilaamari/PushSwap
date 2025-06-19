/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:41:06 by ilaamari          #+#    #+#             */
/*   Updated: 2025/06/19 08:41:06 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Stack Operations */
t_stack	*stack_new(int value);
void	stack_add_bottom(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
t_stack	*stack_before_last(t_stack *stack);

/* Operations */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

/* Algorithm Functions */
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	tiny_sort(t_stack **stack);
void	sort_three(t_stack **stack);
void	turkish_sort(t_stack **stack_a, t_stack **stack_b);

/* Position and Cost Calculation */
void	get_position(t_stack **stack);
void	get_target_position(t_stack **stack_a, t_stack **stack_b);
void	get_cost(t_stack **stack_a, t_stack **stack_b);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

/* Utils */
void	free_stack(t_stack **stack);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
int		find_highest_index(t_stack *stack);
int		find_lowest_index_position(t_stack **stack);
int		abs_value(int n);

/* Input Validation and Parsing */
int		is_number(char *str);
int		has_duplicates(t_stack *stack);
void	assign_index(t_stack *stack_a, int stack_size);
t_stack	*fill_stack_values(int argc, char **argv);

#endif