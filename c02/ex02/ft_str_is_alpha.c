/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:40:37 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/10 13:48:02 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	c = c | 32;
	if (c >= 'a' && c <= 'z' )
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_str_is_alpha(char *str)
{
	int	d;

	if (*str == '\0')
		return (1);
	while (*str != '\0')
	{
		d = ft_isalpha(*str);
		if (d == 1)
			str++;
		if (d == 0)
			return (0);
	}
	return (1);
}
