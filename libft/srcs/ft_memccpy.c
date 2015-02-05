/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:38:45 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:41:26 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int					index;
	char				*dest2;
	const char			*src2;
	unsigned char		i;

	dest2 = dest;
	src2 = src;
	index = 0;
	i = c;
	while (n != 0)
	{
		dest2[index] = src2[index];
		if (src2[index] == i)
			return (&dest2[++index]);
		index++;
		n--;
	}
	return (0);
}
