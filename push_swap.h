/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:08:09 by jomaia            #+#    #+#             */
/*   Updated: 2025/08/06 15:08:17 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_range
{
	int	min;
	int	max;
	int	count_limit;
}	t_range;


int		check_invalid(char *str);
void	free_lists(t_stack *stack_a, t_stack *stack_b);
void	print_errors();
int		split_to_atoi(t_stack **lst, char *str, int i);
void	print_lists(t_stack *stack_a);
void	swap_a(t_stack **stack_a);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	reverse_rotate_a(t_stack **stack_a);
void	swap_b(t_stack **stack_a);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_b(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_a);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	normalize(t_stack **stack_a, int size);
int		check_sorted(t_stack *stack_a);
void	sort_b(t_stack **stack_a, t_stack **stack_b, t_range range);
void	push_b_down(t_stack **stack_a, t_stack **stack_b, int index);
void	push_b_up(t_stack **stack_a, t_stack **stack_b, int index);
void	push_b_down_switch(t_stack **stack_a, t_stack **stack_b, int index);
void	push_b_up_switch(t_stack **stack_a, t_stack **stack_b, int index);
void	push_decider(t_stack **stack_a, t_stack **stack_b, int size);
void	choose_sort(t_stack **stack_a, t_stack **stack_b, int divider);
void print_value (t_stack *a, t_stack *b);

#endif
