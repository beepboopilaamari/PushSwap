/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:35:52 by ilaamari          #+#    #+#             */
/*   Updated: 2025/07/05 20:35:52 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest_index_position(t_stack *stack)
{
	int		highest_index;
	int		position;
	t_stack	*tmp;

	highest_index = find_highest_index(stack);
	position = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index == highest_index)
			return (position);
		position++;
		tmp = tmp->next;
	}
	return (position);
}

void	sort_three(t_stack **stack)
{
	int	highest_pos;

	if (is_sorted(*stack))
		return ;
	highest_pos = find_highest_index_position(*stack);
	if (highest_pos == 0)
		ra(stack);
	else if (highest_pos == 1)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}
