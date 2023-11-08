/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:16:27 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/10 13:49:07 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str != '\0' )
	{
		if (*str >= 32 && *str <= 126)
		{
			str++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
int	main()
{
	char f[] = "DWEEEDDDEDDD";
	printf("%d\n", ft_str_is_printable(f));
	printf("%d\n", ft_str_is_printable("DDDDDDDD")); 
	printf("%d\n", ft_str_is_printable("\n")); 
	printf("%d\n", ft_str_is_printable("88jgdejgdeD   \n"));
	return (0);
}*/
