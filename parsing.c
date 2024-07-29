/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:16:40 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/29 12:43:14 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <string.h>

static int	calculate_total_length(int ac, char **av)
{
	int	i;
	int	total_length;

	i = 1;
	total_length = 0;
	while (i < ac)
		total_length += ft_strlen(av[i++]);
	return (total_length);
}

static char	**process_arguments(int ac, char **av, int *index)
{
	int		i;
	char	**parsed_args;
	char	**tmp;
	int		j;

	i = 1;
	parsed_args = malloc(sizeof(char *) * (calculate_total_length(ac, av) + 1));
	*index = 0;
	while (i < ac)
	{
		tmp = rem_space(av[i++]);
		j = 0;
		while (tmp[j])
		{
			if (!add_checker(tmp[j]))
			{
				printf("error \n ");
				exit(-1);
			}
			parsed_args[(*index)++] = tmp[j++];
		}
		free(tmp);
	}
	parsed_args[*index] = NULL;
	return (parsed_args);
}

char	**parse_args(int ac, char **av, int *length)
{
	int		index;
	char	**parsed_args;

	parsed_args = process_arguments(ac, av, &index);
	if (parsed_args)
	{
		*length = index;
		check_for_repeat(index, parsed_args);
	}
	return (parsed_args);
}
