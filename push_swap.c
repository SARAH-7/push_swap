/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 17:46:04 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack_a **a, char **split_nums)
{
	t_stack_a	*new_node;
	int				value;
	int				i;
	
	if (!is_num(split_nums))
	{
		write(2, "Error\n", 6);
		return ;
	}
	i = 0;
	while (split_nums[i])
	{
		value = ft_atoi(split_nums[i]);
		new_node = malloc(sizeof(t_stack_a));
		if (!new_node)
		{
			write(2, "Error\n", 6);
			return ;
		}
		new_node->content = value;
		new_node->next = NULL;
		ft_lstadd_back(a, new_node);
		i++;
	}
	check_for_doubles(*a);
	
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char			*nums;
	int				i;
	char			*temp;
	char			**split_nums;

	stacks.head_a = NULL;
	stacks.head_b = NULL;
	i = 2;
	nums = NULL;
	if (ac < 2)
		return (0);
	else
	{
		if (!av)
			return (1);
		nums = ft_strdup(av[1]);
		while (av[i])
		{
			temp = ft_strjoin(nums, av[i]);
			free(nums);
			nums = temp;
			i++;
		}
		split_nums = ft_split(nums, ' ');
		free(nums);
		stack_init(&stacks.head_a, split_nums);
		sorted_stack(stacks.head_a);
		if (!sorted_stack(stacks.head_a))
			not_sorting(&stacks);
		// while (stacks.head_a)
		// {
		// 	printf("a node: %d\n", stacks.head_a->content);
		// 	stacks.head_a = stacks.head_a->next;
		// }
		// printf("\n");
		// while (stacks.head_b)
		// {
		// 	printf("b node: %d\n", stacks.head_b->content);
		// 	stacks.head_b = stacks.head_b->next;
		// }
		free_stacks(&stacks);  
	}
	return (0);
}
