/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:12:02 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/15 16:22:50 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_power(int nb, int power)
{
	int	res;

	res = nb;
	if (res > res * nb)
		return (0);
	else if (power > 1)
		return (res * ft_recursive_power(res, power - 1));
	else if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
		return (res);
}
/*
#include <stdio.h>

int main ()
{
    printf("%d\n", ft_recursive_power(0, 0));
    printf("%d\n", ft_recursive_power(0, 3));

    printf("%d\n", ft_recursive_power(2, 7));
    printf("%d\n", ft_recursive_power(2, 4));
    return (0);
}*/
