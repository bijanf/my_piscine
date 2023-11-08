/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:32:33 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/04 08:46:14 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	count;
	int	temp;

	count = 0;
	while (count < (size / 2))
	{
		if (size > 1)
		{
			temp = tab[size - count - 1];
			tab[size - count - 1] = tab[count];
			tab[count] = temp;
		}
		count++;
	}
}
/*
int main()
{
   
    int tab[6] = {1,2,38777,443,40,0};
    int size= 6;
    int count =0;
    while (count<size)
    {
        printf("%d", tab[count]);
        printf(",");
        count++;
    }
    printf("\n");
    ft_rev_int_tab(tab, size);
    count =0;
    while (count<size)
    {
        printf("%d", tab[count]);
        printf(",");
        count++;
    }
   
    return 0;

}*/
