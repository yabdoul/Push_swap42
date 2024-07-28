/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:10:34 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/28 20:47:45 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_stack	*create_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
	{
		free(node);
	}
	node->data = data;
	node->next = NULL;
	return (node);
}

t_stack	*stack_from_args(char **args, int ac)
{
	int		i;
	t_stack	*head;
	t_stack	*current;

	if (ac <= 0)
	{
		return (NULL);
	}
	i = 0;
	head = create_node(atoi(args[i++]));
	current = head;
	while (i < ac)
	{
		current->next = create_node(atoi(args[i++]));
		current = current->next;
	}
	return (head);
}

size_t	ft_strlen(char *s)
{
	size_t	leng;
	int		i;

	leng = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
		{
			leng++;
		}
		i++;
	}
	return (leng);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = stack;
	max = tmp;
	while (tmp)
	{
		if (max->data < tmp->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
