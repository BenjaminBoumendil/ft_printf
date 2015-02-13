/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_sSdDp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:18:28 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/13 20:00:07 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <wchar.h>

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
	wchar_t		*wstr;
	int			c;

	wstr = va_arg(*data->va, wchar_t *);
	if (!wstr)
	{
		COUNT_CHAR(6);
		ft_putstr("(null)");
		return ;
	}
	while (*wstr)
	{
		c = *wstr;
		make_opt_s(data, c);
		wstr++;
	}
}

void			opt_d(t_data *data)
{
	char	*str;

	str = ft_itoa(va_arg(*data->va, int));
	display(data, str);
	free(str);
}

void			opt_D(t_data *data)
{
	char		*str;
	long int	i;

	i = va_arg(*data->va, long);
	str = ft_ltoa(i);
	display(data, str);
	free(str);
}

void		opt_p(t_data *data)
{
	char	*str;
	size_t	c;

	c = va_arg(*data->va, size_t);
	str = ft_utoa_base(c, B_HEX);
	ft_putstr("0x");
	COUNT_CHAR(2);
	display(data, str);
}
