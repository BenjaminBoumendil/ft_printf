/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 13:13:37 by ochase            #+#    #+#             */
/*   Updated: 2015/02/17 22:30:25 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// static void		string_precision_formatting(t_data *data, char *str)
// {
// 	size_t	len;

// 	len = ft_strlen(str);
// 	if (len < data->precision)
// 		return ;
// 	str[len - data->precision] = '\0';
// }

// static size_t	display_padding(char c, size_t len, t_data *data)
// {
// 	size_t	i;
// 	size_t	count;

// 	if (len > data->min_width && len > data->precision)
// 		return (0);
// 	i = 0;
// 	count = (data->min_width > data->precision) ? (data->min_width - len)
// 												: (data->precision - len);
// 	while (i < count)
// 	{
// 		i++;
// 		if (ft_strchr("dDoOuUxX", data->opt) && data->precision > 0)
// 			c = (data->precision > ((count - i) + len)) ? '0' : ' ';
// 		ft_putchar(c);
// 	}
// 	return (i);
// }

// static void		display_plus(t_data *data, char *str)
// {
// 	if (ft_strchr("dDoOuUxXi", data->opt) && data->flag->plus && str[0] != '-')
// 	{
// 		ft_putchar('+');
// 		COUNT_CHAR(1);
// 	}
// }

// static void		display_minus(t_data *data, char *str, size_t len)
// {
// 	char	c;

// 	c = ' ';
// 	if (data->flag->zero && ft_strchr("p", data->opt))
// 		c = '0';
// 	*str == '\0' ? write(1, str, 1) : ft_putstr(str);
// 	if (data->min_width > len)
// 		COUNT_CHAR(display_padding(c, len, data));
// }

// void			display(t_data *data, char *str)
// {
// 	size_t	len;

// 	if (ft_strchr("sS", data->opt) && data->precision > 0)
// 		string_precision_formatting(data, str);
// 	if (!(len = ft_strlen(str)))
// 		len = 1;
// 	if (handle_special_cases(data, &str) == 1)
// 		return ;
// 	if (data->flag->minus)
// 		display_minus(data, str, len);
// 	else
// 	{
// 		display_plus(data, str);
// 		if (data->flag->zero && data->opt != 'o')
// 			COUNT_CHAR(display_padding('0', len, data));
// 		else
// 			COUNT_CHAR(display_padding(' ', len, data));
// 		*str == '\0' ? write(1, str, 1) : ft_putstr(str);
// 	}
// 	COUNT_CHAR(ft_strlen(str));
// }




static void		display_padding(t_data *data, char c, size_t len)
{
	size_t	i;

	if (len < data->min_width)
	{
		i = 0;
		while (i < data->min_width)
		{
			ft_putchar(c);
			i++;
		}
	}
}

static void		display_minus(t_data *data, char *str, size_t len)
{
	char	c;

	c = ' ';
	if (data->flag->zero && ft_strchr("p", data->opt))
		c = '0';
	*str == '\0' ? write(1, str, 1) : ft_putstr(str);
	if (data->min_width > len)
		display_padding(data, c, len);
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
	size_t	len;

	new_str = ft_strdup(str);
	display_precision(data, &new_str);
	display_plus(data, &new_str);
	display_space(data, &new_str);
	len = ft_strlen(new_str);
	if (data->flag->minus)
		display_minus(data, new_str, len);
	else
	{
		if (data->flag->zero && data->opt != 'o')
			display_padding(data, '0', len);
		else
			display_padding(data, ' ', len);
	}
	ft_putstr(new_str);
	COUNT_CHAR(ft_strlen(new_str));
	free(new_str);
}
