/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/24 18:35:04 by sbakhit          ###   ########.fr       */
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

int	stack_init(t_stack **a, char **split_nums)
{
	t_stack	*new_node;
	int		value;
	int		i;

	if (!is_num(split_nums))
	{
		ft_printf("Error\n");
		free_split(split_nums);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (split_nums[i])
	{
		value = ps_atoi(split_nums[i], a, split_nums);
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
		{
			ft_printf("Error\n");
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

char	**parsing_avs(char **av)
{
	int		i;
	char	*tmp;
	char	*str;
	char	**split_nums;

	str = ft_strdup(av[1]);
	if (!str)
		return (NULL);
	i = 2;
	while (av[i])
	{
		tmp = ft_strjoin(str, " ");
		if (!tmp)
			return (free(str), NULL);
		free(str);
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!str)
			return (NULL);
		i++;
	}
	split_nums = ps_split(str, ' ');
	free(str);
	return (split_nums);
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
		split_nums = parsing_avs(av);
		if (!split_nums)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		if (!stack_init(&a, split_nums))
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		if (!sorted_stack(a))
			not_sorting(&a, &b);
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
