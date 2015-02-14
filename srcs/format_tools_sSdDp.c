/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_sSdDp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:18:28 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/14 17:21:36 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			opt_s(t_data *data)
{
	char	*str;

	if (data->modifier->l)
	{
		opt_S(data);
		return ;
	}
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

	if (data->modifier->l || data->modifier->j || data->modifier->z)
		str = ft_ltoa(va_arg(*data->va, long long));
	else if (data->modifier->hh)
		str = ft_itoa((char)va_arg(*data->va, int));
	else
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
