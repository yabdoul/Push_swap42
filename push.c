/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:24:13 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/28 20:47:45 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **stack_b)
{
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
	{
		return ;
	}
	printf("rb\n");
	last = *stack_b;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *stack_b;
	*stack_b = (*stack_b)->next;
	last->next->next = NULL;
}

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		return ;
	}
	printf("rra\n");
	last = *stack_a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!*stack_b)
		exit(1);
	printf("rrb\n");
	last = NULL;
	tmp = *stack_b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack_b;
	(*stack_b) = last;
}

void	ra(t_stack **stack_a)
{
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
	{
		return ;
	}
	last = *stack_a;
	printf("ra\n");
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = *stack_a;
	*stack_a = (*stack_a)->next;
	last->next->next = NULL;
}
