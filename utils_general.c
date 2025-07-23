/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:17:05 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/23 16:21:00 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_errors()
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_lists(t_stack *stack_a, t_stack *stack_b)
{
	clear_lst(stack_a);
	clear_lst(stack_b);
}

void	print_lists(t_stack *stack_a)
{
	t_stack *ptr;

	ptr = stack_a;
	while(ptr)
	{
		printf("%d\n", ptr->value);
		ptr = ptr->next;
	}
}

int	ft_isdigit(char c)
{
	if(c >= '0' && c <= '9')
		return (1);
	return (0);
}