/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:41:19 by ilaamari          #+#    #+#             */
/*   Updated: 2025/06/19 08:41:19 by ilaamari         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = fill_stack_values(argc, argv);
	if (!stack_a || has_duplicates(stack_a))
	{
		free_stack(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	assign_index(stack_a, stack_size(stack_a));
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
