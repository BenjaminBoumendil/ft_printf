/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:13:37 by ochase            #+#    #+#             */
/*   Updated: 2015/02/18 16:46:09 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		check_for_neg_sign(char **str)
{
	char	*new_str;
	char	*tmp;
	size_t	i;
	size_t	y;

	if (ft_strchr(&(*str)[1], '-'))
	{
		i = 0;
		y = 0;
		tmp = *str;
		new_str = ft_memalloc(ft_strlen(*str));
		while (str[0][y])
		{
			if (str[0][y] == '-')
				y++;
			new_str[i] = str[0][y];
			i++;
			y++;
		}
		*str = ft_strjoin("-", new_str);
		free(new_str);
		free(tmp);
	}
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
	new_str = ft_memalloc(len + 1);
	while (i < (min_width - len))
	{
		new_str[i] = c;
		i++;
	}
	return (new_str);
}

static void		display_padding(t_data *data, char c, size_t len, char **str, int rev)
{
	char	*tmp;

	if (len < data->min_width)
	{
		tmp = *str;
		if (!rev)
			*str = ft_strjoin(fill_padding_char(c, data->min_width, len), *str);
		else
			*str = ft_strjoin(*str, fill_padding_char(c, data->min_width, len));
		free(tmp);
	}
}

static void		display_minus(t_data *data, char **str, size_t len)
{
	char	c;

	c = ' ';
	if (data->flag->zero && ft_strchr("p", data->opt))
		c = '0';
	if (data->min_width > len)
		display_padding(data, c, len, str, 1);
}

static void		display_space(t_data *data, char **str)
{
	char	*tmp;

	if (ft_strchr("di", data->opt) && data->flag->space &&
									(*str[0] != '-' && *str[0] != '+'))
	{
		tmp = *str;
		*str = ft_strjoin(" ", *str);
		free(tmp);
	}
}

static void		display_plus(t_data *data, char **str)
{
	char	*tmp;

	if (ft_strchr(NUMBER_OPT, data->opt) && data->flag->plus && *str[0] != '-')
	{
		tmp = *str;
		*str = ft_strjoin("+", *str);
		free(tmp);
	}
}

static char		*number_precision_formatting(size_t precision, char **str)
{
	char	*new_str;
	size_t	len;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	len = (*str[0] == '-') ? ft_strlen(*str) - 1 : ft_strlen(*str);
	if (len < precision)
	{
		new_str = ft_memalloc((len + precision) + 1);
		if (*str[i] == '-')
		{
			new_str[i++] = '-';
			(*str)++;
		}
		while (c < (precision - len))
		{
			new_str[i++] = '0';
			c++;
		}
		while (**str)
		{
			new_str[i++] = **str;
			(*str)++;
		}
		// free(*str);
		return (new_str);
	}
	return (*str);
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
	if (data->precision > 0)
	{
		if (ft_strchr("sS", data->opt))
			string_precision_formatting(data->precision, *str);
		else if (ft_strchr(NUMBER_OPT, data->opt))
			*str = number_precision_formatting(data->precision, str);
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
	len = !ft_strlen(new_str) ? 1 : ft_strlen(new_str);
	if (data->flag->minus)
		display_minus(data, &new_str, len);
	else
	{
		if (data->flag->zero && data->opt != 'o')
			display_padding(data, '0', len, &new_str, 0);
		else
			display_padding(data, ' ', len, &new_str, 0);
	}
	if (ft_strchr(NUMBER_OPT, data->opt) && data->flag->zero)
		check_for_neg_sign(&new_str);
	ft_putstr(new_str);
	if (is_null)
		display_null(data, '\0');
	COUNT_CHAR(ft_strlen(new_str));
	free(new_str);
}
