/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 21:59:19 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/16 18:45:06 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*feed_binary_string(char *str, char *b_mask)
{
	char		*tab;
	int			i;
	int			c;

	tab = ft_strdup(b_mask);
	i = ft_strlen(tab) - 1;
	c = ft_strlen(str) - 1;
	while (i >= 0 && c >= 0)
	{
		if (tab[i] == 'x')
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

static char		*get_display_char(char *str, char *b_mask)
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
		final_str[c] = (char)ft_atoi_base(\
					ft_strncpy(tmp, &tab[c * 8], ft_strlen(tab) / len), "01");
		c++;
	}
	free(tmp);
	free(tab);
	return (final_str);
}

char			*convert_wchar(t_data *data, int c)
{
	char		*str2;
	char		*str;
	size_t		len;

	(void)data;
	str2 = ft_itoa_base(c, "01");
	len = ft_strlen(str2);
	if (len <= 7)
		str = get_display_char(str2, "0xxxxxxx");
	else if (len <= 11)
		str = get_display_char(str2, "110xxxxx10xxxxxx");
	else if (len <= 16)
		str = get_display_char(str2, "1110xxxx10xxxxxx10xxxxxx");
	else
		str = get_display_char(str2, "11110xxx10xxxxxx10xxxxxx10xxxxxx");
	free(str2);
	return (str);
}
