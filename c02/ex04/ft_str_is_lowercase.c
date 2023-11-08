/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:04:12 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/10 13:48:36 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	d;
	int	cc;
	int	dd;

	if (*str == '\0')
		return (1);
	d = 0;
	dd = 0;
	while (*str != '\0')
	{
		cc = '0';
		cc = *str | 32;
		if (cc == *str && cc >= 'a' && cc <= 'z')
		{
			str++;
			dd++;
		}
		else
			return (0);
		d++;
	}
	if (d != dd)
		return (0);
	return (1);
}
/*int main()
{
    // test the function with different characters
    char f[] = "fdwfffefeA";
    printf("%d\n", ft_str_is_lowercase(f)); // prints 1
    printf("%d\n", ft_str_is_lowercase("DDDDDDDD")); // prints 1
    printf("%d\n", ft_str_is_lowercase("dgjhdgejhdgjehfdjefd")); // prints 0
    printf("%d\n", ft_str_is_lowercase("88jgdejgdeD")); // prints 0

    return 0;
}*/
