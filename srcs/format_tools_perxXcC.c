/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_perxXcC.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 15:23:19 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/16 16:26:03 by bboumend         ###   ########.fr       */
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
	char	*tmp;

	data->flag->plus = 0;
	if (data->modifier->hh)
		str = ft_ultoa_base(va_arg(*data->va, unsigned long) % 256, B_HEX);
	else
		str = ft_ultoa_base(va_arg(*data->va, unsigned long), B_HEX);
	if (data->flag->sharp && *str != '0')
	{
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
	}
	display(data, str);
	free(str);
}

void			opt_X(t_data *data)
{
	char	*str;
	char	*tmp;

	data->flag->plus = 0;
	if (data->modifier->hh)
		str = ft_ultoa_base(va_arg(*data->va, unsigned long) % 256, B_HEXM);
	else
		str = ft_ultoa_base(va_arg(*data->va, unsigned long), B_HEXM);
	if (data->flag->sharp && *str != '0')
	{ 
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
	}
	display(data, str);
	free(str);
}

void			opt_c(t_data *data)
{
	char	str[2];
	int		c;

	if (data->modifier->l)
	{
		opt_C(data);
		return ;
	}
	c = va_arg(*data->va, int);
	str[0] = (char)c;
	str[1] = '\0';
	display(data, str);
}

void			opt_C(t_data *data)
{
	int			c;
	char		*str;

	c = va_arg(*data->va, wchar_t);
	str = convert_wchar(data, c);
	display(data, str);
	free(str);
}
