/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:08:26 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/16 19:52:39 by bboumend         ###   ########.fr       */
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

char			*ft_ultoa(unsigned long n)
{
	char			*str;
	unsigned long	i;
	unsigned long	j;
	unsigned long	n1;

	i = 0;
	n1 = n;
	while (n1 != 0)
	{
		n1 = n1 / 10;
		++i;
	}
	str = ft_memalloc(i + 1);
	j = i - 1;
	n_is_null(n, str);
	while (n != 0)
	{
		str[j--] = n % 10 + 48;
		n = n / 10;
	}
	str[i + 1] = '\0';
	return (str);
}
