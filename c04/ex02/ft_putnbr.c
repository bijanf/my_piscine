/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:39:20 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/18 12:12:54 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

int main()
{
    ft_putnbr(-2147483648);
    write(1, "\n", 1);
    ft_putnbr(2147483608);
    write(1, "\n", 1);
    ft_putnbr(8);
    write(1, "\n", 1);
    ft_putnbr(483648);
    write(1, "\n", 1);
    ft_putnbr(0);
    write(1, "\n", 1);

}
