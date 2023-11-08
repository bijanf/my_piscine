/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfallah- <bfallah-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:02:33 by bfallah-          #+#    #+#             */
/*   Updated: 2023/10/10 13:47:07 by bfallah-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*p;

	p = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	dest = dest -1;
	return (p);
}
/*
int main()
{

    char dest[55] = "ffr";
    char src[55]  = "cecdced7979";
    char *d = dest;
    char *s = src;

    d = ft_strcpy(d, s);
    printf("%s\n", d);
    return 0;

}*/
