/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:53:32 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:41:34 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	index;
	char			*dest2;
	const char		*src2;

	dest2 = dest;
	src2 = src;
	index = 0;
	while (n != index)
	{
		dest2[index] = src2[index];
		index++;
	}
	return (dest2);
}
