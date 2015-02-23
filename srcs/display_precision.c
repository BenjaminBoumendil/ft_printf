/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 19:01:59 by ochase            #+#    #+#             */
/*   Updated: 2015/02/23 13:39:34 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		pointer_precision_formatting(size_t precision, char **str)
{
	char	*new_str;
	char	*save;
	char	*tmp;
	char	*value;
	size_t	i;

	if (ft_strlen(*str) < precision)
	{
		i = 0;
		save = *str;
		value = ft_strsplit(*str, 'x')[1];
		new_str = ft_memalloc(precision);
		while (i < precision - ft_strlen(value))
			new_str[i++] = '0';
		tmp = ft_strjoin("0x", new_str);
		*str = ft_strjoin(tmp, value);
		free(new_str);
		free(value);
		free(save);
		free(tmp);
	}
}

static void		number_precision_formatting(size_t precision, char **str)
{
	size_t	len;

	if (!ft_strlen(*str))
		len = 1;
	else
		len = (*str[0] == '-') ? ft_strlen(*str) - 1 : ft_strlen(*str);
	if (len < precision)
		number_precision_loop(str, precision, len);
}

static void		upcase_s_opt_precision_formatting(size_t precision, char *str)
{
	char	c;
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(str);
	if (len < precision)
		return ;
	i = 0;
	while (i < precision)
	{
		c = *str;
		j = 0;
		while ((c & MOST_SIGNIFICANT_BIT_MASK) == MOST_SIGNIFICANT_BIT_MASK)
		{
			c <<= 1;
			j++;
		}
		j = (!j ? 1 : j);
		if (precision - i >= j)
			i += j;
		else
			break ;
	}
	str[i] = '\0';
}

static void		string_precision_formatting(size_t precision, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < precision)
		return ;
	str[precision] = '\0';
}

void			display_precision(t_data *data, char **str)
{
	if (data->precision_called)
	{
		if (ft_strchr("s", data->opt) && data->opt)
			string_precision_formatting(data->precision, *str);
		else if (ft_strchr("S", data->opt) && data->opt)
			upcase_s_opt_precision_formatting(data->precision, *str);
		else if (ft_strchr(NUMBER_OPT, data->opt) && data->opt)
			number_precision_formatting(data->precision, str);
		else if (ft_strchr("p", data->opt) && data->opt)
			pointer_precision_formatting(data->precision, str);
	}
}
