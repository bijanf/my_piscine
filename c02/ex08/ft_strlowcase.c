/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:32:26 by  bfallah-         #+#    #+#             */
/*   Updated: 2023/10/10 13:49:42 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	jj;

	jj = 0;
	while (str[jj])
	{
		if ('A' <= str[jj] && str[jj] <= 'Z')
		{
			str[jj] += 32;
		}
		jj++;
	}
	return (str);
}
