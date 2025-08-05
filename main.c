/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:06:49 by jomaia            #+#    #+#             */
/*   Updated: 2025/08/05 18:57:44 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack_a)
{
	t_stack *ptr;

	ptr = stack_a;
	while (ptr->next)
	{
		if(ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	optimal_divider(int size)
{
	int	divider;
	
	if (size > 400)
		divider = 30;
	else if (size >= 100)
		divider = 10;
	else if (size >= 50)
		divider = 5;
	else if (size >= 10)
		divider = size / 4;
	else
		divider = 4;
	return (divider);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*node;
	
	if (argc < 2)
		print_errors("No arguments");
	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	node = NULL;
	while (++i < argc)
	{
		if (check_invalid(argv[i]) || !split_to_atoi(&stack_a, node, argv[i], 0))
		{
			free_lists(stack_a, stack_b);
			print_errors();
		}
	}
	if (check_sorted(stack_a))
		return (free_lists(stack_a, stack_b), 0);
	i = optimal_divider(ft_lstsize(stack_a));
	choose_sort(&stack_a, &stack_b, i);
	free_lists(stack_a, stack_b);
	return (0);
}