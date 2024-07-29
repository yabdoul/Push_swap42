/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:30:31 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/29 16:11:10 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_tab(int *tab, int val, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min;
	int		min_index;

	min = find_min(*stack_a);
	min_index = 0;
	while (*stack_a != min)
	{
		ra(stack_a);
		min_index++;
	}
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (min_index > 0)
	{
		while (min_index--)
			rra(stack_a);
	}
}

int	get_index_nearest(t_stack *node, int range, int i)
{
	t_stack	*tmp;
	int		j;

	tmp = node;
	j = 0;
	while (tmp)
	{
		if (tmp->index >= i && tmp->index <= range + i)
			return (j);
		tmp = tmp->next;
		j++;
	}
	return (-1);
}

void	large_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	range;
	int	i;

	range = 0.0375 * size + 11.75;
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= range + i)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if (get_index_nearest(*stack_a, range, i) <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*max;
	int		range;
	int		index;

	range = 0.0375 * size + 11.75;
	while (*stack_b)
	{
		max = get_max(*stack_b);
		index = get_node_index(*stack_b, max->data);
		if (index == 0)
			pa(stack_a, stack_b);
		else if (index <= range)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}
