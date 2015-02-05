/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 18:57:12 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:43:03 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		c;
	int		c2;

	c = 0;
	c2 = 0;
	while (dest[c] != '\0')
		c++;
	while (src[c2] != '\0')
	{
		dest[c] = src[c2];
		c++;
		c2++;
	}
	dest[c] = '\0';
	return (dest);
}
