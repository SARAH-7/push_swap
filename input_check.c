/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:55:27 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/19 18:06:11 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	is_num(char **split_nums)
// {
// 	char	*arg;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (split_nums[i])
// 	{
// 		arg = split_nums[i];
// 		j = 0;
		
// 		while (arg[j])
// 		{
// 			printf("pls\n");
// 			if (!ft_isdigit_issign(arg[j]))
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int	is_num(char **split_nums)
{
	char	*arg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (split_nums[i])
	{
		arg = split_nums[i];
		j = 0;
		
		while (arg[j])
		{
			if (!ft_isdigit_issign(arg[j]) || (arg[j + 1] == '-' || arg[j + 1] == '+')
				|| ((arg[j] == '-' || arg[j] == '+') && (arg[j + 1] == ' ' || arg[j + 1] == '\0')))
				return (0);
			j++;
		}
		// printf("\n");
		i++;
	}
	return (1);
}