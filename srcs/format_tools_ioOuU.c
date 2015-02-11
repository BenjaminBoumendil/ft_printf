/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_ioOuU.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 20:52:10 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/11 15:41:17 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		opt_o(t_data *data)
{
	char	*str;

	str = ft_itoa_base(va_arg(*data->va, int), B_OCT);
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
	char	*str;
	int		c;

	c = va_arg(*data->va, int);
	if (c < 0)
		str = ft_utoa(UINT_MAX - NNB(c) + 1);
	else
		str = ft_utoa(c);
	display(data, str);
	free(str);
}

void		opt_per(t_data *data)
{
	display(data, va_arg(*data->va, char *));
}
