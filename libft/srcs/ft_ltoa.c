/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 21:44:23 by ochase            #+#    #+#             */
/*   Updated: 2015/02/09 23:41:43 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*n_is_null(long int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (0);
}

char			*ft_ltoa(long int n)
{
	char					*str;
	long int				i;
	long int				j;
	unsigned long int		n1;
	unsigned long int		n2;

	i = 0;
	n1 = (n > 0 ? (unsigned long)n : -(unsigned long)n);
	n2 = n;
	while (n1 != 0 && i++ >= 0)
		n1 = n1 / 10;
	n >= 0 ? i : (i = i + 1);
	str = ft_memalloc(i + 1);
	j = i - 1;
	n_is_null(n, str);
	while (n2 != 0)
	{
		str[j--] = n2 % 10 + 48;
		n2 = n2 / 10;
	}
	str[i + 1] = '\0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
