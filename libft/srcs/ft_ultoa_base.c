/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 21:53:47 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/13 21:54:32 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ultoa_base(unsigned long n, char *base)
{
	char			*str;
	unsigned long	i;
	unsigned long	n1;

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