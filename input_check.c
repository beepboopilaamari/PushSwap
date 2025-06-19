/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 08:43:59 by ilaamari          #+#    #+#             */
/*   Updated: 2025/06/19 08:43:59 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if string is a valid number */
int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* Check for duplicate values in the stack */
int	has_duplicates(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

/* Simple atoi for parsing integers */
static long	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/* Assign index to each element based on its value (smallest = 1) */
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*tmp;
	t_stack	*highest;
	int		value;

	while (stack_size > 0)
	{
		tmp = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (tmp)
		{
			if (tmp->value == INT_MIN && tmp->index == 0)
				tmp->index = 1;
			if (tmp->value > value && tmp->index == 0)
			{
				value = tmp->value;
				highest = tmp;
			}
			tmp = tmp->next;
		}
		if (highest)
			highest->index = stack_size;
		stack_size--;
	}
}

/* Parse arguments and create the stack */
t_stack	*fill_stack_values(int argc, char **argv)
{
	t_stack	*stack_a;
	long	nb;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (free_stack(&stack_a), NULL);
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (free_stack(&stack_a), NULL);
		stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
