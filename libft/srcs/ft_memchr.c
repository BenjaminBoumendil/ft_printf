/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:35:36 by bboumend          #+#    #+#             */
/*   Updated: 2014/04/18 17:10:51 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int			index;
	const unsigned char		*str;
	unsigned char			c2;

	index = 0;
	str = (const unsigned char *)s;
	c2 = (unsigned char)c;
	while (index < n)
	{
		if (str[index] == c2)
			return ((char *)&str[index]);
		index++;
	}
	return (0);
}
