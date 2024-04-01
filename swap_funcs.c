/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/01 17:29:19 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_func(t_stack_node **a)
{
	int	temp;

	temp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = temp;
}

void	sb_func(t_stack_node **b)
{
	int	temp;

	temp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = temp;
}
