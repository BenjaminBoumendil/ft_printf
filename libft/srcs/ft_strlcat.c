/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:09:19 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:43:32 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	c;
	unsigned int	i;

	i = ft_strlen(src);
	c = ft_strlen(dest);
	if (c >= size)
		return (size + i);
	ft_strncat((dest + c), src, (size - c - 1));
	return (c + i);
}
