/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbakhit <sbakhit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:04:53 by sbakhit           #+#    #+#             */
/*   Updated: 2024/04/19 14:44:48 by sbakhit          ###   ########.fr       */
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
			exit(EXIT_FAILURE);
		}
	}
	else if (sign == -1)
	{
		if ((result == INT_MAX / 10 && a > '8') || result > INT_MAX / 10)
		{
			write(2, "Error\n", 6);	
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

int	ft_atoi(const char *str)
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
		if (of != 1)
			return (0);
		result = result * 10 + *str - '0';
		str++;
	}
	return ((result * sign));
}
