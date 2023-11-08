/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:25:30 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/11 11:17:42 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		res = s1[i] - s2[i];
		if (res != 0)
			return (res);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char s1[] = "ghghjgj";
	char s2[] = "hg";
	char s3[] = "ghghjgj";
	char s4[] = "hg";

	printf("%d\n", ft_strncmp(s1, s2, 3));
	printf("%d\n", strncmp(s3, s4, 3));

}*/
