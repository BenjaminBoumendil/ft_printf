/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_perxXcC.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 15:23:19 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/12 15:40:18 by ochase           ###   ########.fr       */
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
	if (c == 0 && !data->flag->zero)
	{
		COUNT_CHAR(1);
		return ;
	}
	str[0] = (char)c;
	str[1] = '\0';
	display(data, str);
}

void			opt_C(t_data *data)
{
	char	str[2];
	int		c;

	c = va_arg(*data->va, wint_t);
	if (c == 0 && !data->flag->zero)
	{
		COUNT_CHAR(1);
		return ;
	}
	str[0] = (char)c;
	str[1] = '\0';
	display(data, str);
}
