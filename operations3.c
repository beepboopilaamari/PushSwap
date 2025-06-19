/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:56:58 by ilaamari          #+#    #+#             */
/*   Updated: 2025/06/19 08:56:58 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rra and rrb at the same time */
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
	write(1, "rrr\n", 4);
}
