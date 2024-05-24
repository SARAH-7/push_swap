/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:04:53 by sbakhit           #+#    #+#             */
/*   Updated: 2024/05/24 18:14:13 by sbakhit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_for_overflow(long long result, int sign, char a)
{
	if (sign == 1)
	{
		if ((result == INT_MAX / 10 && a > '7') || result > INT_MAX / 10)
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	else if (sign == -1)
	{
		if ((result == INT_MAX / 10 && a > '8') || result > INT_MAX / 10)
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	ps_atoi(const char *str, t_stack **a, char **split_nums)
{
	int		sign;
	long	result;
	int		of;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		of = check_for_overflow(result, sign, *str);
		if (of != 1 && !a && !split_nums)
		{
			free_stack(a);
			free_split(split_nums);
			exit(EXIT_FAILURE);
		}
		result = result * 10 + *str - '0';
		str++;
	}
	return ((result * sign));
}
