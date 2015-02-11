/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:39:08 by ochase            #+#    #+#             */
/*   Updated: 2015/02/11 22:20:20 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_utoa_base(size_t n, char *base)
{
	char			*str;
	size_t			i;
	size_t			n1;

	i = 0;
	n1 = n;
	while (n1 != 0)
	{
		n1 = n1 / ft_strlen(base);
		++i;
	}
	str = ft_memalloc(i + 1);
	i--;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i--] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
	}
	return (str);
}
