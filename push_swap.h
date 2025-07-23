/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:08:09 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/23 16:19:55 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_stack{
	int		value;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

int		ft_isdigit(char c);
int		check_invalid(char *str);
void	free_lists(t_stack *stack_a, t_stack *stack_b);
void	print_errors();
int		split_to_atoi(t_stack **lst, t_stack *node, char *str, int i);
void	print_lists(t_stack *stack_a);
t_stack	*ft_lst_new(int data);
t_stack	*ft_lst_last(t_stack *stack);
void	ft_lst_add_back(t_stack **stack, t_stack *node);
void	ft_lst_add_front(t_stack **stack, t_stack *node);
void	clear_lst(t_stack *lst);

#endif
