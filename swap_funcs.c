/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/22 23:32:41 by sbakhit          ###   ########.fr       */
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

void	swap_func(t_stack **t, char ch)
{
	if (t == NULL || (*t)->next == NULL)
		return ;
	swap_op(t);
	ft_printf("s%c\n", ch);
}
