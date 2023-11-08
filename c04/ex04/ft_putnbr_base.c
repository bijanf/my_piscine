/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  bfallah- < bfallah-@student.42berlin.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:51:16 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/14 11:06:18 by  bfallah-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	print_base_nb(int nbr, char *base, int size)
{
	char	c;
	int		n;

	n = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= size)
		print_base_nb(n / size, base, size);
	c = base[n % size];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	s;

	s = 0;
	if (check_base(base) == 1)
	{
		while (base[s] != '\0')
			s++;
		print_base_nb(nbr, base, s);
	}
}
/*
int	main()
{
    ft_putnbr_base(16, "0123456789ABCDEF");
    write(1, "\n", 1);
    ft_putnbr_base(-8, "poneyvif");
    write(1, "\n", 1);
    ft_putnbr_base(550, "-1");
    write(1, "\n", 1);
    ft_putnbr_base(550, "22");
    write(1, "\n", 1);
    ft_putnbr_base(10, "01");
    write(1, "\n", 1);
}
*/
