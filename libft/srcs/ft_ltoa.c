/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 21:44:23 by ochase            #+#    #+#             */
/*   Updated: 2015/02/13 19:38:52 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa(long int n)
{
	char			*str;
	long int		i;
	long int		n1;
	long int		n2;

	i = 0;
	n1 = (n > 0 ? n : -n);
	n2 = (n < 0 ? n * -1: n);
	while (n1 != 0 && i++ >= 0)
		n1 = n1 / 10;
	n >= 0 ? i : (i = i + 1);
	str = ft_memalloc(i + 1);
	i--;
	if (n == 0)
		str[0] = '0';
	while (n2 != 0)
	{
		str[i--] = n2 % 10 + 48;
		n2 = n2 / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
