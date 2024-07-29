/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:55:13 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/29 16:10:15 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *node)
{
	t_stack	*tmp;

	tmp = node;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

void	free_stacks_tab(t_stack *stack_a, t_stack *stack_b, int *tab)
{
	free_all(stack_a);
	free_all(stack_b);
	free(tab);
}

void	free_args(char **parsed_args, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(parsed_args[i]);
		i++;
	}
	free(parsed_args);
}

int	main(int ac, char **av)
{
	int		total_length;
	t_stack	*stack_b;
	char	**parsed_args;
	t_stack	*stack_a;
	int		*tab_tmp;

	check_final(ac, av);
	total_length = 0;
	stack_b = NULL;
	parsed_args = parse_args(ac, av, &total_length);
	stack_a = stack_from_args(parsed_args, total_length);
	tab_tmp = args_to_array(stack_a);
	if (!check_sorted(stack_a))
	{
		printf("error \n ");
		exit(-1);
	}
	sort_array(tab_tmp, stack_a);
	indexing(tab_tmp, stack_a);
	rendering_by_size(&stack_a, &stack_b, total_length);
	free_stacks_tab(stack_a, stack_b, tab_tmp);
	free_args(parsed_args, total_length);
}

///todo fix sort five algo 
