/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:55:46 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:43:54 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		c;

	c = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	else if (c > n)
		return (0);
	while (*s1 && n > 0)
	{
		if (!ft_strncmp(s1, s2, c))
			return ((char*)s1);
		++s1;
		--n;
	}
	return (0);
}
