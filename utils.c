/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:17:05 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/22 19:34:48 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_errors()
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	clear_lst(t_list *lst)
{
	t_list	*ptr;
	
	ptr = lst;
	while(ptr)
	{
		lst = lst->next;
		free(ptr);
		ptr = lst;
	}
}

void	free_lists(t_list *stack_a, t_list *stack_b)
{
	clear_lst(stack_a);
	clear_lst(stack_b);
}