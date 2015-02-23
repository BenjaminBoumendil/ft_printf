/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_precision_tools.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 13:38:15 by ochase            #+#    #+#             */
/*   Updated: 2015/02/23 13:38:36 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		number_precision_loop(char **str, size_t precision, size_t len)
{
	char	*save;
	char	*new_str;
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
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
