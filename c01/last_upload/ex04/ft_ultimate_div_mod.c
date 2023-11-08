/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:13:58 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/04 16:46:53 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a % temp;
	*a = *a / temp;
}
/*
int	main()
{
    int a = 13;
    int b = 5;
    printf("%d is divided by %d \n", a, b);
    ft_ultimate_div_mod(&a, &b);
    printf("RESULT: %d\nREMAINDER: %d \n", a, b);
}*/
