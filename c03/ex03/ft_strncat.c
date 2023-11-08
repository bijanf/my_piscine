/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:25:59 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/16 10:52:13 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	j = 0;
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int main()
{
char s1[] = "Laba ";
char s2[] = "Diena";

char s3[] = "Laba ";
char s4[] = "Diena";

printf("%s\n", ft_strncat(s1, s2, 3));
printf("%s\n", s1);
printf("%s\n", s2);
printf("%s\n", strncat(s3, s4, 3));
printf("%s\n", s3);
printf("%s\n", s4);
}*/
