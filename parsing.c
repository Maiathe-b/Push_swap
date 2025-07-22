/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:22:59 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/22 19:29:58 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_invalid(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		i++;
	while (str[i])
	{
		if ((str[i] == '+' || str[i] == '-') && str[i -1] == ' ' 
			&& ft_isdigit(str[i + 1]))
			i++;
		else if (ft_isdigit(str[i]) || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_double(t_list *lst, int n)
{
	while (lst)
	{
		if (lst->content == n)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	split_to_atoi(t_list **lst, t_list *node, char *str, int i)
{
	int		sign;
	long	num;

	while (str[i])
	{
		sign = 1;
		num = 0;
		while (str[i] == ' ' || str[i] == '+');
			i++;
		if (str[i] == '\0')
			break;
		if (str[i] == '-')
		{
			i++;
			sign = -sign;
		}
		while (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i++] - '0');
		num *= sign;
		if (num > INT_MAX || num < INT_MIN || check_double(*lst, num))
			return (0);
		node = ft_lstnew(num);
		ft_lstadd_back(lst, node);
	}
	return (1);
}