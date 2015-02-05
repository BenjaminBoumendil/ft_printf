/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:19:24 by bboumend          #+#    #+#             */
/*   Updated: 2014/04/18 16:52:32 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int		c;
	char				*str;
	int					size;

	c = 0;
	if (s && f)
	{
		size = ft_strlen(s);
		str = ft_memalloc(size + 1);
		while (s[c])
		{
			str[c] = f(c, s[c]);
			++c;
		}
		str[c] = '\0';
		return (str);
	}
	return (0);
}
