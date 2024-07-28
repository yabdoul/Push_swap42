/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabdoul <yabdoul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:46:56 by yabdoul           #+#    #+#             */
/*   Updated: 2024/07/28 20:56:53 by yabdoul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct stack_s
{
	int				data;
	int				index;
	struct stack_s	*next;
}					t_stack;

typedef struct data_s
{
	int				size;
	int				rem;
	int				pivot1;
	int				pivot2;
}					t_data;

t_stack				*create_node(int data);
t_stack				*add_to_list(t_stack *head, t_stack *node);
void				t_stacko_list(int ac, char **av, t_stack *head);
void				check_final(int ac, char **av);
char				**ft_split(const char *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(char *s);
char				**parse_args(int ac, char **av, int *length);
int					ft_isdigit(char *c);
t_stack				*stack_from_args(char **args, int ac);
void				check_for_repeat(int ac, char **av);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
int					*args_to_array(t_stack *stack_a);
void				sort_array(int *arr, t_stack *stack_a);
void				indexing(int *arr, t_stack *stack_a);
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack_a, t_stack **stack_b);
void				sort_four(t_stack **stack_a, t_stack **stack_b);
int					get_node_index(t_stack *stack, int val);
int					pivot_cmp(int pivot1, t_stack *stack_a);
size_t				lst_size(t_stack *head);
void				large_sort(t_stack **stack_a, t_stack **stack_b, int size);
void				sort_stack_b(t_stack **sa, t_stack **sb, int size);
t_stack				*get_max(t_stack *stack);
int					check_sorted(t_stack *stack_a);
int					ft_atoi(const char *nptr);
char				*ft_strchr(const char *s, int c);
t_stack				*find_min(t_stack *stack_a);
int					add_checker(char *s);
void				free_chars(char **str, int size);
char				**rem_space(char *av);
void				set_algo_data(t_stack *stack_a, t_data *data);

#endif
