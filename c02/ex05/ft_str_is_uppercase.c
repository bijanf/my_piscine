/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:04:08 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/10 13:48:49 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
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
		if (cc != *str && cc >= 'a' && cc <= 'z')
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
