/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:59:36 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:40:31 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*n_is_null(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (0);
}

char			*ft_itoa_base(long unsigned int n, char *base)
{
	char					*str;
	int						i;
	int						j;
	long unsigned int		n1;
	int						b;

	i = 0;
	n1 = n;
	b = ft_strlen(base);
	while (n1 != 0 && i++ >= 0)
		n1 = n1 / b;
	str = ft_memalloc(i + 1);
	j = i - 1;
	n_is_null(n, str);
	while (n != 0)
	{
		str[j--] = base[n % b];
		n = n / b;
	}
	str[i + 1] = '\0';
	return (str);
}
