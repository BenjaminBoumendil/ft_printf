/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 21:44:23 by ochase            #+#    #+#             */
/*   Updated: 2015/02/16 19:52:27 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ltoa(long int n)
{
	char			*str;
	long int		i;
	long int		n1;

	i = 0;
	n1 = n;
	while (n1 != 0 && i++ >= 0)
		n1 = n1 / 10;
	n >= 0 ? i : (i = i + 1);
	str = ft_memalloc(i + 1);
	i--;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		n1 = (n % 10);
		str[i--] = (n1 < 0 ? (-n1 + 48) : (n1 + 48));
		n = n / 10;
	}
	return (str);
}
