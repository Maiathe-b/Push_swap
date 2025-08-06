/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:54:52 by jomaia            #+#    #+#             */
/*   Updated: 2025/08/06 15:46:07 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_cost(t_stack *stack_b, int index)
{
	t_stack	*top;
	int		cost_top;
	
	top = stack_b;
	cost_top = 0;
	while (top->next)
	{
		if (top->index == index)
			break;
		cost_top++;
		top = top->next;
	}
	return(cost_top);
}

int	bottom_cost(t_stack *stack_b, int index)
{
	t_stack	*bottom;
	int		cost_bottom;

	cost_bottom = 1;
	bottom = ft_lstlast (stack_b);
	while (bottom->prev)
	{
		if(bottom->index == index)
			break;
		cost_bottom++;
		bottom = bottom->prev;
	}
	return (cost_bottom);
}

int	push_cost(t_stack *stack_b, int index)
{
	int	cost_top;
	int	cost_bottom;

	cost_top = top_cost(stack_b, index);
	cost_bottom = bottom_cost(stack_b, index);
	if (cost_top < cost_bottom)
		return (cost_top);
	return (cost_bottom);
}

void	push_decider(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size < 2)
		push_a(stack_a, stack_b);
	else if (push_cost(*stack_b, size) <= push_cost(*stack_b, size - 1))
	{
		if (top_cost(*stack_b, size) < bottom_cost(*stack_b, size))
			push_b_up (stack_a, stack_b, size);
		else
			push_b_down(stack_a, stack_b, size);
		if (top_cost(*stack_b, size - 1) < bottom_cost(*stack_b, size -1))
			push_b_up(stack_a, stack_b, size - 1);
		else
			push_b_down(stack_a, stack_b, size - 1);
	}
	else
	{
		if (top_cost (*stack_b, size - 1) < bottom_cost(*stack_b, size - 1))
			push_b_up (stack_a, stack_b, size - 1);
		else
			push_b_down (stack_a, stack_b, size - 1);
		if (top_cost (*stack_b, size) < bottom_cost(*stack_b, size))
			push_b_up_switch (stack_a, stack_b, size);
		else
			push_b_down_switch (stack_a, stack_b, size);
	}
}