/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:19:33 by bboumend          #+#    #+#             */
/*   Updated: 2014/04/18 17:26:09 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	int		c;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (s)
	{
		c = ft_strlen(s) - 1;
		str = ft_memalloc(c + 1);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			++i;
		while (s[c] == ' ' || s[c] == '\n' || s[c] == '\t')
			--c;
		while (s[i] && i != (c + 1))
		{
			str[i2] = s[i];
			++i;
			++i2;
		}
		str[i2] = '\0';
		return (str);
	}
	return (0);
}
