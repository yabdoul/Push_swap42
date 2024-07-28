/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_etc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:24:58 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/28 20:47:45 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;

	if (*stack_a == NULL)
	{
		printf("stack_a is NULL in pb function\n");
		return ;
	}
	printf("pb\n");
	top = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_b == NULL)
	{
		*stack_b = top;
		(*stack_b)->next = NULL;
	}
	else
	{
		top->next = *stack_b;
		*stack_b = top;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_b;

	if (*stack_b == NULL)
	{
		return ;
	}
	printf("pa\n");
	top_b = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_a == NULL)
	{
		*stack_a = top_b;
		(*stack_a)->next = NULL;
	}
	else
	{
		top_b->next = *stack_a;
		*stack_a = top_b;
	}
}

void	sa(t_stack **stack_a)
{
	int	helper;

	if (!*stack_a || !(*stack_a)->next)
		exit(1);
	printf("sa\n ");
	helper = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = helper;
}

void	sb(t_stack **stack_b)
{
	int	helper;

	if (!*stack_b || !(*stack_b)->next)
		exit(1);
	printf("sb\n ");
	helper = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = helper;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		exit(1);
	sa(&stack_a);
	sb(&stack_b);
}
