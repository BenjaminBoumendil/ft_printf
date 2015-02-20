/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:13:37 by ochase            #+#    #+#             */
/*   Updated: 2015/02/20 18:37:51 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		move_sign(char **str, char sign)
{
	char	*new_str;
	char	*save;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	save = *str;
	new_str = ft_memalloc(ft_strlen(*str));
	while (str[0][y])
	{
		if (str[0][y] == sign)
			y++;
		new_str[i] = str[0][y];
		i++;
		y++;
	}
	*str = ft_strjoin(&sign, new_str);
	free(new_str);
	free(save);
}

static void		check_for_sign(char **str)
{
	if (ft_strchr(&(*str)[1], '-'))
		move_sign(str, '-');
	else if (ft_strchr(&(*str)[1], '+'))
		move_sign(str, '+');
}

static void		display_null(t_data *data, char c_null)
{
	if (ft_strchr("cC", data->opt))
	{
		write(1, &c_null, 1);
		COUNT_CHAR(1);
	}
}

static char		*fill_padding_char(char c, size_t min_width, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	new_str = ft_memalloc(min_width + 1);
	while (i < (min_width - len))
	{
		new_str[i] = c;
		i++;
	}
	return (new_str);
}

static void		display_padding(t_data *data, char c, size_t len, char **str, int rev)
{
	char	*save;

	if (len < data->min_width)
	{
		save = *str;
		if (!rev && !data->flag->space)
			*str = ft_strjoin(fill_padding_char(c, data->min_width, len), *str);
		else
			*str = ft_strjoin(*str, fill_padding_char(c, data->min_width, len));
		free(save);
	}
}

static void		display_rev_padding(t_data *data, char **str, size_t len)
{
	char	c;

	c = ' ';
	if (!data->flag->minus && ft_strchr("p", data->opt))
		c = '0';
	if (data->min_width > len)
		display_padding(data, c, len, str, 1);
}

static void		handle_padding(t_data *data, char **new_str, size_t len)
{
	if (data->flag->minus || (data->opt == 'p' && data->flag->zero))
		display_rev_padding(data, new_str, len);
	else
	{
		if (!data->precision && data->flag->zero && data->opt != 'o')
			display_padding(data, '0', len, new_str, 0);
		else
			display_padding(data, ' ', len, new_str, 0);
	}
	if (ft_strchr(NUMBER_OPT, data->opt) && data->flag->zero)
		check_for_sign(new_str);
}

static void		display_space(t_data *data, char **str)
{
	char	*save;

	if (ft_strchr("di", data->opt) && data->flag->space &&
									(*str[0] != '-' && *str[0] != '+'))
	{
		save = *str;
		*str = ft_strjoin(" ", *str);
		free(save);
	}
}

static void		display_plus(t_data *data, char **str)
{
	char	*save;

	if (ft_strchr("dDuUxXi", data->opt) && data->flag->plus && *str[0] != '-')
	{
		save = *str;
		*str = ft_strjoin("+", *str);
		free(save);
	}
}

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
	char	*new_str;
	char	*save;
	size_t	len;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	if (!ft_strlen(*str))
		len = 1;
	else
		len = (*str[0] == '-') ? ft_strlen(*str) - 1 : ft_strlen(*str);
	if (len < precision)
	{
		save = *str;
		new_str = (*str[i] == '-') ? ft_memalloc(precision + 2)
									: ft_memalloc(precision + 1);
		if (*str[i] == '-')
		{
			new_str[i++] = '-';
			(*str)++;
		}
		while (c++ < (precision - len))
			new_str[i++] = '0';
		c = 0;
		while ((*str)[c])
			new_str[i++] = (*str)[c++];
		*str = ft_strjoin("", new_str);
		free(save);
		free(new_str);
	}
}

static void		Sopt_precision_formatting(size_t precision, char *str)
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

static void		display_precision(t_data *data, char **str)
{
	if (data->precision_called)
	{
		if (ft_strchr("s", data->opt) && data->opt)
			string_precision_formatting(data->precision, *str);
		else if (ft_strchr("S", data->opt) && data->opt)
			Sopt_precision_formatting(data->precision, *str);
		else if (ft_strchr(NUMBER_OPT, data->opt) && data->opt)
			number_precision_formatting(data->precision, str);
		else if (ft_strchr("p", data->opt) && data->opt)
			pointer_precision_formatting(data->precision, str);
	}
}

void			display(t_data *data, char *str)
{
	char	*new_str;
	bool	is_null;
	size_t	len;

	is_null = !*str ? true : false;
	new_str = ft_strdup(str);
	display_precision(data, &new_str);
	display_plus(data, &new_str);
	display_space(data, &new_str);
	if (!*new_str && data->precision_called && ft_strchr("sS", data->opt)
		&& data->opt)
		len = ft_strlen(new_str);
	else
		len = !ft_strlen(new_str) ? 1 : ft_strlen(new_str);
	handle_padding(data, &new_str, len);
	ft_putstr(new_str);
	if (is_null == true)
		display_null(data, '\0');
	COUNT_CHAR(ft_strlen(new_str));
	free(new_str);
}
