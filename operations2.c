/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:43:21 by ilaamari          #+#    #+#             */
/*   Updated: 2025/06/19 08:43:21 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = stack_last(*stack_a);
	tmp->next = NULL;
	last->next = tmp;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = stack_last(*stack_b);
	tmp->next = NULL;
	last->next = tmp;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		last = stack_last(*stack_a);
		tmp->next = NULL;
		last->next = tmp;
	}
	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		last = stack_last(*stack_b);
		tmp->next = NULL;
		last->next = tmp;
	}
	write(1, "rr\n", 3);
}

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*before_last;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	before_last = stack_before_last(*stack_a);
	tmp = before_last->next;
	before_last->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*before_last;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	before_last = stack_before_last(*stack_b);
	tmp = before_last->next;
	before_last->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	write(1, "rrb\n", 4);
}
