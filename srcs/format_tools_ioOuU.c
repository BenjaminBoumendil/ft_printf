/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_ioOuU.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 20:52:10 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/13 22:53:20 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		opt_o(t_data *data)
{
	char	*str;

	if (data->modifier->hh)
		str = ft_ultoa_base(va_arg(*data->va, unsigned long int) % 256, B_OCT);
	else
		str = ft_itoa_base(va_arg(*data->va, long int), B_OCT);
	display(data, str);
	free(str);
}

void		opt_O(t_data *data)
{
	char	*str;

	str = ft_ltoa_base(va_arg(*data->va, long int), B_OCT);
	display(data, str);
	free(str);
}

void		opt_u(t_data *data)
{
	char			*str;

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
