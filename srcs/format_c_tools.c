/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 21:59:19 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/12 22:30:25 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*feed_binary_string(char *str, char *b_mask)
{
	char		*tab;
	size_t		i;
	size_t		c;

	tab = ft_strdup(b_mask);
	i = ft_strlen(tab) - 1;
	c = ft_strlen(str) - 1;
	while (i != 0)
	{
		if (tab[i] == 'x' && str[c])
			tab[i] = str[c--];
		i--;
	}
	i = 0;
	while (tab[i])
	{
		if (tab[i] == 'x')
			tab[i] = '0';
		i++;
	}
	return (tab);
}

char			*get_display_char(char *str, char *b_mask)
{
	char		*final_str;
	char		*tmp;
	char		*tab;
	size_t		len;
	size_t		c;

	c = 0;
	len = ft_strlen(b_mask) / 8;
	final_str = ft_memalloc(len + 1);
	tab = feed_binary_string(str, b_mask);
	tmp = ft_memalloc(ft_strlen(tab) / len);
	while (c < len)
	{
		final_str[c] = ft_atoi_base( \
						ft_strncpy(tmp, &tab[c * 8], ft_strlen(tab) / len), 2);
		c++;
	}
	free(tmp);
	free(tab);
	return (final_str);
}
