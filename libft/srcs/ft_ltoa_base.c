/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:34:15 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/10 22:41:59 by bboumend         ###   ########.fr       */
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

char			*ft_ltoa_base(long int n, char *base)
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
		str[j--] = base[n2 % ft_strlen(base)];
		n2 = n2 / ft_strlen(base);
	}
	str[i + 1] = '\0';
	if (n < 0)
		str[0] = '-';
	return (str);
}