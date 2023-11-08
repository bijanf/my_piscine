/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  bfallah- < bfallah-@student.42berlin.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:07:06 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/10 13:49:25 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	jj;

	jj = 0;
	while (str[jj])
	{
		if ('a' <= str[jj] && str[jj] <= 'z')
		{
			str[jj] -= 32;
		}
		jj++;
	}
	return (str);
}
/*
int main()
{
    char f[] = "DWEEEDDDEDDDakjlgh386893463kjgkjhg";
    printf("%s\n", ft_strupcase(f)); // prints 0
    return 0;
}*/
