/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:42:32 by ilaamari          #+#    #+#             */
/*   Updated: 2025/06/19 08:42:32 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rotate both stacks in the same direction */
static void	do_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

/* Reverse rotate both stacks in the same direction */
static void	do_rev_rota_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

/* Rotate stack A until it reaches the target position */
static void	do_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

/* Rotate stack B until it reaches position 0 */
static void	do_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

/* Execute the move to get B element to its target position in A */
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		do_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		do_rev_rota_both(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	pa(stack_a, stack_b);
}
