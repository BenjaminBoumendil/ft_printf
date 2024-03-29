/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:34:15 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/11 22:42:43 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa_base(long int n, char *base)
{
	char					*str;
	long int				i;
	size_t					len;
	unsigned long int		n1;
	unsigned long int		n2;

	i = 0;
	len = ft_strlen(base);
	n1 = (n > 0 ? (unsigned long)n : -(unsigned long)n);
	n2 = n;
	while (n1 != 0 && i++ >= 0)
		n1 = n1 / len;
	n >= 0 ? i : (i = i + 1);
	str = ft_memalloc(i + 1);
	i--;
	if (n == 0)
		str[0] = '0';
	while (n2 != 0)
	{
		str[i--] = base[n2 % len];
		n2 = n2 / len;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
