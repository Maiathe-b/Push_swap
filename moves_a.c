/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:20:41 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/23 18:54:58 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack_a)
{
	t_stack	*temp;
	
	if ((*stack_a)->next)
	{
		temp = (*stack_a);
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->prev = temp;
		write(1, "sa\n", 3);
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *node;
	if (!*stack_b)
		return ;
	node = *stack_b;
	if (!(*stack_b)->next)
		*stack_b = NULL;
	else
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
	}
	if (!*stack_a)
	{
		*stack_a = node;
		(*stack_a)->prev = NULL;
		(*stack_a)->next = NULL;
	}
	else
	{
		(*stack_a)->prev = node;
		node->next = *stack_a;
		*stack_a = node;
	}
	write(1, "pa\n", 3);
}

void	rotate_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if(*stack_a)
		return ;
	first = *stack_a;
	last = ft_lst_last(*stack_a);
	*stack_a = (*stack_a)->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_a)
		return ;
	first = *stack_a;
	last = ft_lst_last(*stack_a);
	first->prev = last;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	*stack_a = last;
	write(1, "rra\n", 4);
}