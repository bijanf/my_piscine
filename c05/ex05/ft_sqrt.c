/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:14:38 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/15 16:24:51 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	j;

	j = 1;
	if (nb > 0)
	{
		while (j * j <= nb)
		{
			if (j * j == nb)
				return (j);
			if (j > 46340)
				return (0);
			j++;
		}
	}
	return (0);
}
/*
#include <stdio.h>

int main ()
{
    printf("%d\n", ft_sqrt(16));
    printf("%d\n", ft_sqrt(32));
    printf("%d\n", ft_sqrt(3));
    printf("%d\n", ft_sqrt(20));
    printf("%d\n", ft_sqrt(256));
    printf("%d\n", ft_sqrt(64));

    return (0);
}*/
