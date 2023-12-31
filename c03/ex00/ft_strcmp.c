/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:05:55 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/16 10:53:16 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	k = 0;
	while (s1[k] != '\0' || s2[k] != '\0')
	{
		res = s1[k] - s2[k];
		if (res != 0)
			return (res);
		k++;
	}
	return (0);
}
