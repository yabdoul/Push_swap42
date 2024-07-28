/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:20:58 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/28 20:47:45 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	if (nptr[i + 1] == '-' || nptr[i + 1] == '+')
	{
		printf("error\n");
		exit(-1);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = (result * 10) + (nptr[i++] - '0');
	return (result * sign);
}
