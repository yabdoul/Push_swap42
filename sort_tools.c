/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:11:20 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/28 20:49:35 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*args_to_array(t_stack *stack_a)
{
	int		i;
	int		*res_arr;
	t_stack	*tmp;

	i = 0;
	if (!stack_a)
		exit(1);
	res_arr = malloc(sizeof(int) * lst_size(stack_a));
	tmp = stack_a;
	while (tmp)
	{
		res_arr[i++] = tmp->data;
		tmp = tmp->next;
	}
	return (res_arr);
}

void	sort_array(int *arr, t_stack *stack_a)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < lst_size(stack_a))
	{
		j = i;
		while (j < lst_size(stack_a))
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	indexing(int *arr, t_stack *stack_a)
{
	size_t	i;
	t_stack	*tmp;

	i = 0;
	tmp = stack_a;
	if (!arr || !stack_a)
		exit(0);
	while (tmp)
	{
		i = 0;
		while (i < lst_size(stack_a))
		{
			if (arr[i] == tmp->data)
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

int	get_node_index(t_stack *stack, int val)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->data == val)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	set_algo_data(t_stack *stack_a, t_data *data)
{
	data->size = lst_size(stack_a);
}
