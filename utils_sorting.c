/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:36:00 by jomaia            #+#    #+#             */
/*   Updated: 2025/08/05 16:48:32 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimal_rotate(t_stack **stack_a, t_stack **stack_b, t_range range)
{
	push_b (stack_a, stack_b);
	if ((*stack_a)->index > range.max)
	{
		rotate_both (stack_a, stack_b);
		return ;
	}
	else
	{
		rotate_b (stack_b);
		return ;
	}
}

void	sort_b(t_stack **stack_a, t_stack **stack_b, t_range range)
{
	int	count;

	count = 0;
	while (ft_lstsize(*stack_a) > 3 && count < (range.max - range.min) * 2)
	{
		if ((*stack_a)->index < range.min && 
		(*stack_a)->index < range.count_limit)
		{
			optimal_rotate (stack_a, stack_b, range);
			count++;
		}
		else if ((*stack_a)->index <= range.max &&
		(*stack_a)->index < range.count_limit)
		{
			push_b (stack_a, stack_b);
			count++;
		}
		else
			rotate_a(stack_a);
	}
}