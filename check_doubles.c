/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:52:59 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/21 18:32:49 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_doubles(t_stack *a)
{
	t_stack	*tmp;
	t_stack	*ptr;
	int		num;

	ptr = a;
	while (ptr != NULL)
	{
		tmp = ptr;
		num = tmp->content;
		tmp = tmp->next;
		while (tmp != NULL)
		{
			if (num == tmp->content)
			{
				write(2, "Error\n", 6);
				free_stack(&a);
				exit (EXIT_FAILURE);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}
