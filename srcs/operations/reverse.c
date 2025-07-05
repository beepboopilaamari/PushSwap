/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:35:23 by ilaamari          #+#    #+#             */
/*   Updated: 2025/07/05 20:35:23 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr("rra\n");
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
	ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*before_last;

	if (*stack_a && (*stack_a)->next)
	{
		before_last = stack_before_last(*stack_a);
		tmp = before_last->next;
		before_last->next = NULL;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	if (*stack_b && (*stack_b)->next)
	{
		before_last = stack_before_last(*stack_b);
		tmp = before_last->next;
		before_last->next = NULL;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
	ft_putstr("rrr\n");
}
