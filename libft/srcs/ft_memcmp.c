/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:02:07 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:41:31 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char		*str1;
	const char		*str2;
	unsigned int	index;

	index = 0;
	str1 = s1;
	str2 = s2;
	if (!s1 && !s2)
		return (0);
	while (index < n)
	{
		if (str1[index] == str2[index])
			index++;
		else
			return ((unsigned char)str1[index] - (unsigned char)str2[index]);
	}
	return (0);
}
