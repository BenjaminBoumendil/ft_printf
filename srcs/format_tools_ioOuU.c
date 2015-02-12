/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_ioOuU.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 20:52:10 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/12 19:17:06 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		opt_o(t_data *data)
{
	char	*str;

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

void		opt_U(t_data *data)
{
	char		*str;
	long int	i;

	i = va_arg(*data->va, long);
	str = ft_ultoa(i);
	display(data, str);
	free(str);
}
