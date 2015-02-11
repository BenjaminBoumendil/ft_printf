/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_ioOuU.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 20:52:10 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/11 17:53:16 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// void		opt_i(t_data *data)
// {
// }

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

// void		opt_U(t_data *data)
// {
// }