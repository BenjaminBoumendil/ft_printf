/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:15:12 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:41:41 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		index;
	char				*dest2;
	const char			*src2;
	char				*copy;

	index = 0;
	dest2 = dest;
	src2 = src;
	copy = ft_memalloc(n);
	while (index < n)
	{
		copy[index] = src2[index];
		index++;
	}
	index = 0;
	while (index < n)
	{
		dest2[index] = copy[index];
		index++;
	}
	free(copy);
	return (dest);
}
