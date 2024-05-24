/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/24 18:03:27 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_op(t_stack **t)
{
	int	tmp;

	tmp = (*t)->content;
	(*t)->content = (*t)->next->content;
	(*t)->next->content = tmp;
}

void	swap_func(t_stack **t, char ch)
{
	if (t == NULL || (*t)->next == NULL)
		return ;
	swap_op(t);
	if (ch == 'a')
		ft_printf("sa\n");
	else if (ch == 'b')
		ft_printf("sb\n");
	// if (i == 1)
	// else if (i == 2)
	// else if (i == 3)
	// {
	// 	if (a == NULL || (*a)->next == NULL || b == NULL
	// 		|| (*b)->next == NULL)
	// 		return ;
	// 	sa_func(a);
	// 	sb_func(b);
	// 	ft_printf("ss\n");
	// }
}
