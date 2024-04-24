/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:52:59 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/24 13:45:30 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_doubles(t_stack_a *a)
{
	t_stack_a	*tmp;
	t_stack_a	*ptr;
	int			num;

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
				// free_stacks(a);
				exit (0);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}