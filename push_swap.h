/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:08:09 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/22 19:35:10 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h/libft.h"
# include "limits.h"

typedef struct	s_stack{
	int		value;
	void	*next;
	void	*prev;
}			t_stack;

int		check_invalid(char *str);
void	free_lists(t_list *stack_a, t_list *stack_b);
void	print_errors();
int		split_to_atoi(t_list **lst, t_list *node, char *str, int i);

#endif
