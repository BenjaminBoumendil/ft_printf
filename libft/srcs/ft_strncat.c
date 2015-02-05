/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:02:48 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:43:40 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int	c;
	unsigned int	c2;

	c = 0;
	c2 = 0;
	while (dest[c] != '\0')
		c++;
	while (src[c2] != '\0' && c2 < n)
	{
		dest[c] = src[c2];
		c++;
		c2++;
	}
	dest[c] = '\0';
	return (dest);
}
