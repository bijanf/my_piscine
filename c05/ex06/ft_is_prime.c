/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:15:08 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/15 16:26:07 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	i;
	int	res;

	i = 2;
	res = 0;
	if (nb < 2)
		return (0);
	if (nb == i)
		return (1);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			res++;
		i++;
	}
	if (res == 0)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main ()
{
    printf("%d\n", ft_is_prime(16));
    printf("%d\n", ft_is_prime(32));
    printf("%d\n", ft_is_prime(3));
    printf("%d\n", ft_is_prime(20));
    printf("%d\n", ft_is_prime(256));
    printf("%d\n", ft_is_prime(97));

    return (0);
}*/
