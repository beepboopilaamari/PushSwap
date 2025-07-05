/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:31:42 by ilaamari          #+#    #+#             */
/*   Updated: 2025/07/05 20:31:42 by ilaamari         ###   ########.fr       */
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

t_stack		*stack_new(int value);
int			stack_add_bottom(t_stack **stack, t_stack *new);
int			stack_size(t_stack *stack);
t_stack		*stack_last(t_stack *stack);
t_stack		*stack_before_last(t_stack *stack);

void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

void		push_swap(t_stack **stack_a, t_stack **stack_b);
void		sort_three(t_stack **stack);
void		turkish_sort(t_stack **stack_a, t_stack **stack_b);

void		get_position(t_stack **stack);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);
void		get_cost(t_stack **stack_a, t_stack **stack_b);
void		do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void		do_mv(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);

void		free_stack(t_stack **stack);
int			is_sorted(t_stack *stack);
int			find_highest_index(t_stack *stack);
int			find_lowest_index_position(t_stack **stack);
int			abs_value(int n);

int			is_number(char *str);
int			has_duplicates(t_stack *stack);
void		assign_index(t_stack *stack_a, int stack_size);
t_stack		*parse_arguments(int argc, char **argv);

void		ft_putstr(char *str);
void		ft_putstr_fd(char *str, int fd);
long		ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
void		free_split_array(char **arr);
char		*ft_strchr(const char *s, int c);
int			ft_isdigit(int c);

#endif