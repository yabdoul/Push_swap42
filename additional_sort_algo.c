/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_sort_algo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:29:23 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/29 16:07:16 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *stack_a)
{
	t_stack	*min;
	t_stack	*helper;

	min = stack_a;
	helper = stack_a;
	while (helper)
	{
		if (min->data > helper->data)
			min = helper;
		helper = helper->next;
	}
	return (min);
}

void	sort_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	min = find_min(*stack_a);
	while (*stack_a != min)
		rra(stack_a);
	pb(stack_a, stack_b);
	if ((*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
	pa(stack_a, stack_b);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;

	min = find_min(*stack_a);
	while (*stack_a != min)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	rendering_by_size(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 3)
		sort_three(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else if (size == 4)
		sort_four(stack_a, stack_a);
	else
	{
		large_sort(stack_a, stack_b, size);
		sort_stack_b(stack_a, stack_b, size);
	}
}
