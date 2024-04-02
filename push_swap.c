/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 14:52:58 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/02 19:43:11 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_check(char **av)
{
	char	*arg;
	int		i;

	i = 0;
	while (av[i])
	{
		arg = av[i];
		if (!(arg[0] >= '0' && arg[0] <= '9')
			&& !((arg[0] == '-' || arg[0] == '+')
				&& (arg[1] >= '0' && arg[1] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

void	stack_init(t_stack_node **a, char **av)
{
	t_stack_node	*new_node;
	int				value;
	int				i;

	if (!input_check(av))
		printf("Error: Invalid input\n");
	else
	{
		i = 0;
		while (av[i])
		{
			value = atoi(av[i]);
			new_node = malloc(sizeof(t_stack_node));
			if (!new_node)
			{
				printf("Error: Memory allocation failed\n");
				return ;
			}
			new_node->content = value;
			new_node->next = NULL;
			ft_lstadd_back(a, new_node);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	else
	{
		av = ft_split(av[1], ' ');
		if (!av)
			return (1);
		stack_init(&a, av);
		sorted_stack(a);
		if (!sorted_stack(a))
			not_sorting(&a, &b);
		while (a)
		{
			printf("a node: %d\n", a->content);
			a = a->next;
		}
		printf("\n");
		while (b)
		{
			printf("b node: %d\n", b->content);
			b = b->next;
		}
		// free(av);
	}
	return (0);
}
