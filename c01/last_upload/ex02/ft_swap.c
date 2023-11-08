/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:59:38 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/04 09:01:48 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b; 
	*b = temp;
}
/*int main()
{
	int	a1;
	int	b1;
	int	*a;
	int	*b;

	a1 = 33040000;	
	b1 = 24545735;

	a = &a1;
	b = &b1;

	printf("%d",*a);
        printf("---------");
        printf("%d",*b);
	printf("\n");
	ft_swap( a, b);

	printf("%d",*a);
	printf("---------");
	printf("%d",*b);
	

}*/
