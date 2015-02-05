/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:06:18 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:41:45 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char		i;
	unsigned int		index;
	unsigned char		*str;

	i = c;
	index = 0;
	str = s;
	while (index < n)
	{
		str[index] = i;
		index++;
	}
	return (s);
}
