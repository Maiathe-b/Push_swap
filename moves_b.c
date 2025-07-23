/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:56:00 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/23 18:57:51 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack **stack_b)
{
	t_stack	*temp;
	
	if ((*stack_b)->next)
	{
		temp = (*stack_b);
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->prev = temp;
		write(1, "sb\n", 3);
	}
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
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
	if (!*stack_b)
	{
		*stack_b = node;
		(*stack_b)->prev = NULL;
		(*stack_b)->next = NULL;
	}
	else
	{
		(*stack_b)->prev = node;
		node->next = *stack_b;
		*stack_b = node;
	}
	write(1, "pb\n", 3);
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if(*stack_b)
		return ;
	first = *stack_b;
	last = ft_lst_last(*stack_b);
	*stack_b = (*stack_b)->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	reverse_rotate_a(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack_b)
		return ;
	first = *stack_b;
	last = ft_lst_last(*stack_b);
	first->prev = last;
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	*stack_b = last;
	write(1, "rrb\n", 4);
}