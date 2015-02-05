/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:05:22 by bboumend          #+#    #+#             */
/*   Updated: 2014/04/15 23:04:14 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	c2;

	index = ft_strlen(s);
	c2 = c;
	while (index > 0)
	{
		if (s[index] == c2)
			return ((char*)&s[index]);
		index--;
	}
	if (s[index] == c2)
		return ((char*)&s[index]);
	return (0);
}
