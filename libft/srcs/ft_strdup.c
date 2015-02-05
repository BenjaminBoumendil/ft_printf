/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:29:00 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:43:25 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		c;
	int		c2;

	c = 0;
	c2 = ft_strlen(str);
	dest = ft_memalloc(c2 + 1);
	if (dest == 0)
		return (0);
	while (str[c] != '\0')
	{
		dest[c] = str[c];
		c++;
	}
	dest[c] = '\0';
	return (dest);
}
