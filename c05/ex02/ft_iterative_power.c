/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:11:20 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/15 16:21:34 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	return (result);
}
/*
#include <stdio.h>

int main ()
{
    printf("%d\n", ft_iterative_power(0, 0));
    printf("%d\n", ft_iterative_power(0, 3));
    printf("%d\n", ft_iterative_power(2, 0));
    printf("%d\n", ft_iterative_power(2, 7));
    printf("%d\n", ft_iterative_power(2, 3));
    return (0);
}*/
