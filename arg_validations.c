/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:27:06 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/28 15:09:33 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_char(char c)
{
	if ((c < '0' || c > '9') && (c != ' ') && (c != '-'))
	{
		printf("Error\n");
		exit(1);
	}
}

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	if (c[0] == '\0')
	{
		printf("Error\n");
		exit(1);
	}
	while (c[i])
	{
		check_char(c[i]);
	
		i++;
	}
	return (1);
}

void	check_args_numerique(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_isdigit(av[i++]))
			exit(1);
	}
}

void	check_for_repeat(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = i;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j++]))
			{
				printf("error\n");
				exit(1);
			}
		}
		i++;
	}
}

void	check_final(int ac, char **av)
{
	check_args_numerique(ac, av);
	check_for_repeat(ac, av);
}
