/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:10:39 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:43:43 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	c;

	c = 0;
	while ((s1[c] || s2[c]) && c < n)
	{
		if (s1[c] == s2[c])
			c++;
		else
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
	}
	return (0);
}
