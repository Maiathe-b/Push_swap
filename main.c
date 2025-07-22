/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:06:49 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/22 19:36:58 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*node;
	
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
	if ()
}