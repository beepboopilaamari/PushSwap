/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaamari <ilaamari@42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:32:47 by ilaamari          #+#    #+#             */
/*   Updated: 2025/07/05 20:32:47 by ilaamari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_split_arg(char *arg, t_stack **stack_a)
{
	char	**split;
	long	nb;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	j = 0;
	while (split[j])
	{
		if (!is_number(split[j]))
			return (free_split_array(split), 0);
		nb = ft_atoi(split[j]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (free_split_array(split), 0);
		if (!stack_add_bottom(stack_a, stack_new((int)nb)))
			return (free_split_array(split), 0);
		j++;
	}
	free_split_array(split);
	return (1);
}

static int	process_single_arg(char *arg, t_stack **stack_a)
{
	long	nb;

	if (!is_number(arg))
		return (0);
	nb = ft_atoi(arg);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (stack_add_bottom(stack_a, stack_new((int)nb)));
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!process_split_arg(argv[i], &stack_a))
				return (free_stack(&stack_a), NULL);
		}
		else
		{
			if (!process_single_arg(argv[i], &stack_a))
				return (free_stack(&stack_a), NULL);
		}
		i++;
	}
	return (stack_a);
}
