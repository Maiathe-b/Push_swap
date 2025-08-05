/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:30:36 by jomaia            #+#    #+#             */
/*   Updated: 2025/08/05 18:40:58 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b_down(t_stack **stack_a, t_stack **stack_b, int index)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == index)
			return (push_a(stack_a, stack_b));
		else
			reverse_rotate_b(stack_b);
	}
}

void	push_b_up(t_stack **stack_a, t_stack **stack_b, int index)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == index)
			return (push_a(stack_a, stack_b));
		else
			rotate_b(stack_b);
	}
}

void	push_b_down_switch(t_stack **stack_a, t_stack **stack_b, int index)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == index)
		{
			push_a(stack_a, stack_b);
			swap_a(stack_a);
			return ;
		}
		else
			reverse_rotate_b(stack_b);
	}
}

void	push_b_up_switch(t_stack **stack_a, t_stack **stack_b, int index)
{
	while (*stack_b)
	{
		if ((*stack_b)->index == index)
		{
			push_a(stack_a, stack_b);
			swap_a(stack_a);
			return ;
		}
		else
			rotate_b(stack_b);
	}
}