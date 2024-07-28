/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:32:26 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/28 20:47:45 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	lst_size(t_stack *head)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && (unsigned char)c != s[i])
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

int	add_checker(char *s)
{
	int	i;
	int	checker;

	i = 0;
	checker = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			checker++;
		i++;
	}
	if (checker <= 1)
		return (1);
	else
		return (0);
}

void	free_chars(char **str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**rem_space(char *av)
{
	char	**result;

	result = ft_split(av, ' ');
	if (!result)
	{
		return (NULL);
	}
	return (result);
}
