/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  bfallah- < bfallah-@student.42berlin.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:45:55 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/14 10:50:21 by  bfallah-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
/*
#include<stdio.h>

int main()
{
    printf("%d\n", ft_atoi(" ---+--+1234ab567"));
    printf("%d\n", ft_atoi(" ---+--+1 234ab567"));
    printf("%d\n", ft_atoi(" ---+--+1 234ab 567"));
    printf("%d\n", ft_atoi(" ---+--+123\n4ab 567"));
}*/