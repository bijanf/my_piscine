/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:43:52 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/02 13:59:30 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main()
{
	int	a=456;
	int	b=45;
	int	div;
	int	mod;

	ft_div_mod(a,b,&div,&mod);
	printf("first number is %d\n",a);
	printf("second number is %d\n",b);
	printf("div is %d\n",div);
	printf("mod is %d\n",mod);

}*/
