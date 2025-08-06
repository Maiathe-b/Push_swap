#include "push_swap.h"

void sort_three(t_stack **stack)
{
	t_stack	*last;
	int		sec;
	int		third;

	last = ft_lstlast (*stack);
	if((*stack)->value > (*stack)->next->value)
		swap_a(stack);
	sec = (*stack)->next->value;
	third = last->value;
	if (third < sec && third < (*stack)->value)
		reverse_rotate_a(stack);
	else if (third < sec)
	{
		reverse_rotate_a(stack);
		swap_a(stack);
	}
}

void	normalize(t_stack **stack_a, int size)
{
	int		counter;
	int		index;
	t_stack	*smallest;
	t_stack	*stack;

	counter = 0;
	index = 1;
	while (counter < size)
	{
		stack = *stack_a;
		while (stack->index != 0)
			stack = stack->next;
		smallest = stack;
		stack = *stack_a;
		while (stack)
		{
			if (stack->value < smallest->value && stack->index == 0)
				smallest = stack;
			stack = stack->next;
		}
		smallest->index = index;
		index++;
		counter++;
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	normalize(stack_a, 4);
	while (*stack_a)
	{
		if ((*stack_a)->index == 1)
		{
			push_b (stack_a, stack_b);
			break;
		}
		else
			rotate_a (stack_a);
	}
	if(!check_sorted (*stack_a))
		sort_three (stack_a);
	push_a(stack_a, stack_b);
}

void	norm_push(t_stack **stack_a, t_stack **stack_b, int size,
		int divider)
{
	t_range	range;

	normalize(stack_a, size);
	print_value (*stack_a, *stack_b);
	range.min = divider;
	range.max = range.min * 2;
	range.count_limit = size - 2;
	while (ft_lstsize(*stack_a) > 3)
	{
		sort_b (stack_a, stack_b, range);
		range.min += (divider * 2);
		range.max += (divider * 2);
		print_value (*stack_a, *stack_b);
	}
}

void	choose_sort(t_stack **stack_a, t_stack **stack_b, int divider)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		return (swap_a(stack_a));
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else
	{
		norm_push(stack_a, stack_b, size, divider);
		if(!check_sorted(*stack_a))
			sort_three(stack_a);
		print_value (*stack_a, *stack_b);
		while (ft_lstsize (*stack_b) > 0)
			push_decider(stack_a, stack_b, ft_lstsize(*stack_b));
	}
}