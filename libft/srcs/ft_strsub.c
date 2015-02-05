/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:47:43 by bboumend          #+#    #+#             */
/*   Updated: 2014/04/18 16:57:20 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int		c;
	char				*str;

	c = 0;
	if (s)
	{
		str = ft_memalloc(len + 1);
		while (c != len)
		{
			str[c] = s[start];
			c++;
			start++;
		}
		str[c] = '\0';
		return (str);
	}
	return (0);
}
