/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:27:21 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/23 16:14:23 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_new(int data)
{
	t_stack	*new;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_lst_last(t_stack *stack)
{
	t_stack	*ptr;
	
	ptr = stack;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void	ft_lst_add_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;
	
	if(!stack || !node)
		return ;
	if (*stack == NULL)
		*stack = node;
	else
	{
		last = ft_lst_last(*stack);
		last->next = node;
		node->prev = last;
	}
	node->next = NULL;
}

void	ft_lst_add_front(t_stack **stack, t_stack *node)
{
	node->next = *stack;
	if(*stack)
		(*stack)->prev = node;
	*stack = node;
	(*stack)->prev = NULL;
}

void	clear_lst(t_stack *lst)
{
	t_stack	*ptr;
	
	ptr = lst;
	while(ptr)
	{
		lst = lst->next;
		free(ptr);
		ptr = lst;
	}
}
