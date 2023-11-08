/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:32:52 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/16 10:57:24 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[len])
	{
		dest[len + i] = src[len];
		len++;
	}
	dest[len + i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
char s1[] = "Laba ";
char s2[] = "Diena";

char s3[] = "Laba ";
char s4[] = "Diena";

printf("%s\n", ft_strcat(s1, s2));
printf("%s\n", strcat(s3, s4));
}*/
