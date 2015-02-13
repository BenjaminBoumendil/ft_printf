/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_perxXcC.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 15:23:19 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/13 16:47:43 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <wchar.h>

void		opt_per(t_data *data)
{
	display(data, "%");
}

void			opt_x(t_data *data)
{
	char	*str;

	str = ft_utoa_base(va_arg(*data->va, unsigned int), B_HEX);
	display(data, str);
	free(str);
}

void			opt_X(t_data *data)
{
	char	*str;

	str = ft_utoa_base(va_arg(*data->va, unsigned int), B_HEXM);
	display(data, str);
	free(str);
}

void			opt_c(t_data *data)
{
	char	str[2];
	int		c;

	c = va_arg(*data->va, int);
	str[0] = (char)c;
	str[1] = '\0';
	display(data, str);
}

void			opt_C(t_data *data)
{
	int			c;
	char		*str;
	char		*str2;
	size_t		len;

	c = va_arg(*data->va, wchar_t);
	str2 = ft_itoa_base(c, "01");
	len = ft_strlen(str2);
	if (len <= 7)
	{
		display(data, (char*)&c);
		free(str2);
		return ;
	}
	else if (len <= 11)
		str = get_display_char(str2, "110xxxxx10xxxxxx");
	else if (len <= 16)
		str = get_display_char(str2, "1110xxxx10xxxxxx10xxxxxx");
	else
		str = get_display_char(str2, "11110xxx10xxxxxx10xxxxxx10xxxxxx");
	display(data, str);
	free(str);
	free(str2);
}
