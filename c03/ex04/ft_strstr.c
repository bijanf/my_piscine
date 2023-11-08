/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  bfallah- < bfallah-@student.42berlin.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 20:15:35 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/16 11:26:49 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0') 
	{
		return (str);
	}
	while (str[i] != '\0' )
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0') 
			{
				return (&str[i]); 
			}
			j++;
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>

int main()
{
char s1[] = "Laba Diena hede99030303 038403 ";
char s2[] = "Diena";

char s3[] = "Laba Diena hede99030303 038403 ";
char s4[] = "Diena";

printf("%s\n", ft_strstr(s1, s2));
printf("%s\n", strstr(s3, s4));
}*/
