/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_ioOuU.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 20:52:10 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/16 15:17:33 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		opt_o(t_data *data)
{
	char	*str;

	if (data->modifier->hh)
		str = ft_ultoa_base(va_arg(*data->va, unsigned long int) % 256, B_OCT);
	else if (data->modifier->h)
		str = ft_utoa_base((unsigned short)va_arg(*data->va, unsigned int), B_OCT);
	else if (data->modifier->l || data->modifier->ll || data->modifier->j ||
				data->modifier->z)
		str = ft_ultoa_base(va_arg(*data->va, unsigned long), B_OCT);
	else
		str = ft_utoa_base(va_arg(*data->va, unsigned int), B_OCT);
	display(data, str);
	free(str);
}

void		opt_O(t_data *data)
{
	char	*str;
	size_t	len;

	str = ft_ultoa_base(va_arg(*data->va, long int), B_OCT);
	len = ft_strlen(str);
	if (data->flag->sharp && data->precision <= len + 1)
		data->precision = len + 1;
	display(data, str);
	free(str);
}

void		opt_u(t_data *data)
{
	char			*str;

	data->flag->plus = 0;
	if (data->modifier->hh)
		str = ft_itoa(va_arg(*data->va, unsigned int) % 256);
	else
		str = ft_ultoa(va_arg(*data->va, unsigned long));
	display(data, str);
	free(str);
}

void		opt_U(t_data *data)
{
	char		*str;
	long int	i;

	i = va_arg(*data->va, long);
	str = ft_ultoa(i);
	display(data, str);
	free(str);
}
