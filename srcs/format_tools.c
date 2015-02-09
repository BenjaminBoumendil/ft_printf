/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:18:28 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/09 19:33:04 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			opt_s(t_data *data)
{
	char	*str;

	str = va_arg(*data->va, char *);
	if (str)
		display(data, str);
	else
		display(data, "(null)");
}

void			opt_S(t_data *data)
{
	char	*str;
	str = va_arg(*data->va, char *);
	if (str)
	{
		COUNT_CHAR(ft_strlen(str));
		ft_putstr(str);
	}
	else
	{
		COUNT_CHAR(6);
		ft_putstr("(null)");
	}
}

void			opt_d(t_data *data)
{
	COUNT_CHAR(1);
	ft_putnbr(va_arg(*data->va, int));
}

void			opt_D(t_data *data)
{
	COUNT_CHAR(1);
	ft_putnbr(va_arg(*data->va, int));
}

void			opt_c(t_data *data)
{
	COUNT_CHAR(1);
	ft_putchar(va_arg(*data->va, int));
}
