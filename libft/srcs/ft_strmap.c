/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:37:44 by bboumend          #+#    #+#             */
/*   Updated: 2014/04/18 16:52:37 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		c;
	char	*str;
	int		size;

	c = 0;
	if (s && f)
	{
		size = ft_strlen(s);
		str = malloc(sizeof(char) * (size + 1));
		while (s[c])
		{
			str[c] = f(s[c]);
			++c;
		}
		str[c] = '\0';
		return (str);
	}
	return (0);
}
