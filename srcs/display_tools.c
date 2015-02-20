/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 19:04:55 by ochase            #+#    #+#             */
/*   Updated: 2015/02/20 19:32:17 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		move_sign(char **str, char *sign)
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
		if (str[0][y] == *sign)
			y++;
		new_str[i] = str[0][y];
		i++;
		y++;
	}
	*str = ft_strjoin(sign, new_str);
	free(new_str);
	free(save);
}

void			check_for_sign(char **str)
{
	if (ft_strchr(&(*str)[1], '-'))
		move_sign(str, "-");
	else if (ft_strchr(&(*str)[1], '+'))
		move_sign(str, "+");
}

void			display_null(t_data *data, char c_null)
{
	if (ft_strchr("cC", data->opt))
	{
		write(1, &c_null, 1);
		COUNT_CHAR(1);
	}
}

void			display_space(t_data *data, char **str)
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

void			display_plus(t_data *data, char **str)
{
	char	*save;

	if (ft_strchr("dDuUxXi", data->opt) && data->flag->plus && *str[0] != '-')
	{
		save = *str;
		*str = ft_strjoin("+", *str);
		free(save);
	}
}
