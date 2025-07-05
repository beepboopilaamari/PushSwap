/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:32:23 by ilaamari          #+#    #+#             */
/*   Updated: 2025/07/05 20:32:23 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = stack_size(*stack_a);
	if (size_a == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (size_a == 3)
		sort_three(stack_a);
	else if (size_a > 3 && !is_sorted(*stack_a))
		turkish_sort(stack_a, stack_b);
}
