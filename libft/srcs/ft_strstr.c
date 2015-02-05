/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:20:26 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:44:00 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	c;

	c = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*s1)
	{
		if (!ft_strncmp(s1, s2, c))
			return ((char *)s1);
		++s1;
	}
	return (0);
}
