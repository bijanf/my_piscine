/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:31:04 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/11 13:44:43 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	len = 0;
	while (dest[len] != '\0' && len < size)
	{
		len++;
	}
	while (src[i])
	{
		i++;
	}
	return (len + i);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
int main()
{
char s1[] = "Laba 4973jglk3g";
char s2[] = "Dienavvvvv";

char s3[] = "Laba 4973jglk3g";
char s4[] = "Dienavvvvv";

printf("%d\n", ft_strlcat(s1, s2, 3));
printf("%s\n",s1);
printf("%s\n",s2);
printf("%ld\n", strlcat(s3, s4, 3));
printf("%s\n",s3);
printf("%s\n",s4);

return 0;
}*/
