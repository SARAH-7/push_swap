/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/25 03:32:27 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_op(t_stack **t)
{
	int	tmp;

	if (!(*t) || !(*t)->next)
		return ;
	tmp = (*t)->content;
	(*t)->content = (*t)->next->content;
	(*t)->next->content = tmp;
}

void	swap_func(t_stack **a, t_stack **b, char ch)
{
	if (ch == 'a')
	{
		if (a == NULL || (*a)->next == NULL)
			return ;
		swap_op(a);
	}
	else if (ch == 'b')
	{
		if (b == NULL || (*b)->next == NULL)
			return ;
		swap_op(b);
	}
	else
	{
		if (a == NULL || (*a)->next == NULL || b == NULL
			|| (*b)->next == NULL)
			return ;
		swap_op(a);
		swap_op(b);
	}
	ft_printf("s%c\n", ch);
}
