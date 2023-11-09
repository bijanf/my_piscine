/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  bfallah- < bfallah-@student.42berlin.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 00:01:03 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/13 00:05:09 by  bfallah-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_prime(int nb)
{
    int i;
        
    i = 2;
    if (nb == 0 || nb == 1) 
        return (0);
    while (i <= nb/i)
    {
        if (nb % i == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}
int ft_find_next_prime(int nb)
{
     while ( ft_is_prime(nb) != 1)
    {
        nb++;
    }
    return (nb);

}
/*
#include <stdio.h>

int main ()
{
    printf("%d\n", ft_find_next_prime(16));
    printf("%d\n", ft_find_next_prime(32));
    printf("%d\n", ft_find_next_prime(3));
    printf("%d\n", ft_find_next_prime(20));
    printf("%d\n", ft_find_next_prime(256));
    printf("%d\n", ft_find_next_prime(97));

    return (0);
}*/