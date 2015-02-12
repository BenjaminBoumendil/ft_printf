/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:59:36 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/12 19:12:36 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(long unsigned int n, char *base)
{
	char		*str;
	int			i;
	int			j;
	size_t		n1;
	size_t		len;

	i = 0;
	n1 = n;
	len = ft_strlen(base);
	while (n1 != 0 && i++ >= 0)
		n1 = n1 / len;
	str = ft_memalloc(i + 1);
	j = i - 1;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[j--] = base[n % len];
		n = n / len;
	}
	return (str);
}
