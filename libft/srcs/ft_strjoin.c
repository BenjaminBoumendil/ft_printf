/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:59:11 by bboumend          #+#    #+#             */
/*   Updated: 2014/04/18 16:58:53 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	int		c;

	if (s1 && s2)
	{
		c = ft_strlen(s1);
		c = c + ft_strlen(s2);
		str = ft_memalloc(c);
		str = ft_strcat(str, s1);
		str = ft_strcat(str, s2);
		return (str);
	}
	return (0);
}
