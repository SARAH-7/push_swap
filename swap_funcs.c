/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:19:24 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/05 22:16:14 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_func(t_stack_node **a)
{
	int	temp;

	if (*a && (*a)->next)
	{
		temp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = temp;
		printf("sa\n");
	}
}

void	sb_func(t_stack_node **b)
{
	int	temp;

	if (*b && (*b)->next)
	{
		temp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = temp;
		printf("sb\n");
	}
}

void	ss_func(t_stack_node **a, t_stack_node **b)
{
	sa_func(a);
	sb_func(b);
	printf("ss\n");
}

// void sa_func(t_stack_node **a) {
//     if (*a && (*a)->next) {
//         int temp = (*a)->content;
//         (*a)->content = (*a)->next->content;
//         (*a)->next->content = temp;
//         printf("sa\n");
//     }
// }

// void sb_func(t_stack_node **b) {
//     if (*b && (*b)->next) {
//         int temp = (*b)->content;
//         (*b)->content = (*b)->next->content;
//         (*b)->next->content = temp;
//         printf("sb\n");
//     }
// }