/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:55:13 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/28 21:00:51 by yabdoul          ###   ########.fr       */
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
	check_final(ac, av);
	int total_length = 0;
	t_stack *stack_b = NULL;
	t_data *algo_data = malloc(sizeof(t_data));
	char **parsed_args = parse_args(ac, av, &total_length);
	t_stack *stack_a = stack_from_args(parsed_args, total_length);
	int *tab_tmp = args_to_array(stack_a);
	if (!check_sorted(stack_a))
	{
		printf("error \n ");
		exit(-1);
	}
	sort_array(tab_tmp, stack_a);
	indexing(tab_tmp, stack_a);
	set_algo_data(stack_a, algo_data);
	if (algo_data->size == 3)
		sort_three(&stack_a, &stack_b);
	else if (algo_data->size == 5)
		sort_five(&stack_a, &stack_b);
	else if (algo_data->size == 4)
		sort_four(&stack_a, &stack_a);
	else
	{
		int size = algo_data->size;
		large_sort(&stack_a, &stack_b, size);
		sort_stack_b(&stack_a, &stack_b, size);
	}
	t_stack *tmp = stack_b;
	while (tmp)
	{
		printf("%d \n ", tmp->data);
		tmp = tmp->next;
	}
	free_stacks_tab(stack_a, stack_b, tab_tmp);
	free_args(parsed_args, algo_data->size);
	free(algo_data);
}