/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_tools_sSdDp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:18:28 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/11 17:29:11 by bboumend         ###   ########.fr       */
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
	va_arg(*data->va, char *);
	COUNT_CHAR(-1);
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
	void	*p;
	char	*str;
	int		c;
	p = va_arg(*data->va, void*);
	c = ft_atoi_base(p, 16);
	str = ft_itoa(c);
	display(data, str);
}
