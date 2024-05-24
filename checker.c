/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:07:07 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/25 01:10:32 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

	i = 2;
	str = ft_strdup(av[1]);
	if (!str)
		return (NULL);
	if (!input_check(&av[1]))
	{
		ft_printf("Error\n");
		free(str);
		exit(EXIT_FAILURE);
	}
	while (av[i])
	{
		tmp = ft_strjoin(str, " ");
		if (!tmp)
			return (free(str), NULL);
		free(str);
		if (!input_check(&av[i]))
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		str = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (!str)
			return (NULL);
		i++;
	}
	split_nums = ft_split(str, ' ');
	return (free(str), split_nums);
}

void	instructions(t_stack **a, t_stack **b, char *temp)
{
	if (ft_strncmp(temp, "sa\n", 4) == 0)
		swap_op(a);
	else if (ft_strncmp(temp, "sb\n", 4) == 0)
		swap_op(b);
	else if (ft_strncmp(temp, "pa\n", 4) == 0)
		pa_func(a, b);
	else if (ft_strncmp(temp, "pb\n", 4) == 0)
		pb_func(a, b);
	else if (ft_strncmp(temp, "ra\n", 4) == 0)
		ra_func(a);
	else if (ft_strncmp(temp, "rb\n", 4) == 0)
		rb_func(b);
	else if (ft_strncmp(temp, "rr\n", 4) == 0)
		rotate_func(a, b, 'r');
	else if (ft_strncmp(temp, "rra\n", 5) == 0)
		rra_func(a);
	else if (ft_strncmp(temp, "rrb\n", 5) == 0)
		rrb_func(b);
	else if (ft_strncmp(temp, "rrr\n", 5) == 0)
		rev_rotate_func(a, b, 'z');
	else
	{
		ft_printf("Error\n");
		exit (EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_nums;
	char	*temp;

	a = NULL;
	b = NULL;
	split_nums = NULL;
	if (ac > 1 && av && (ft_strncmp(av[0], "./checker", 9) == 0))
	{
		split_nums = parsing_avs(av);
		stack_init(&a, split_nums);
		// free_split(split_nums);
		
		while (1)
		{
			temp = get_next_line(0);
			if (!temp)
				break ;
			instructions(&a, &b, temp);
			free(temp);
			temp = NULL;
		}
		if (sorted_stack(a) && b == NULL)
			ft_printf("OK\n");
		else
		{
			ft_printf("KO\n");
			return (1);
		}
		free_stack(&a);
		free_stack(&b);
	}
	return (0);
}
INT_MAX