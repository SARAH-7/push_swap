/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/29 19:52:35 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split_nums)
{
	int	i;

	i = 0;
	while (split_nums[i])
		free(split_nums[i++]);
	free(split_nums);
}

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	stack_init(t_stack **a, char **split_nums)
{
	t_stack	*new_node;
	int		value;
	int		i;

	i = 0;
	while (split_nums[i])
	{
		value = ps_atoi(split_nums[i], a, split_nums);
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
		{
			write(2, "Error\n", 6);
			free_split(split_nums);
			free_stack(a);
			exit(EXIT_FAILURE);
		}
		new_node->content = value;
		new_node->next = NULL;
		pb_lstadd_back(a, new_node);
		i++;
	}
	free_split(split_nums);
	check_for_doubles(*a);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_nums;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if (ft_strlen(av[1]) <= 0)
			error_msg();
		split_nums = parsing_avs(av);
		if (!split_nums)
			error_msg();
		if (!stack_init(&a, split_nums))
			error_msg();
		if (!sorted_stack(a))
			not_sorting(&a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
