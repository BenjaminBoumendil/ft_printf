/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:38:20 by bboumend          #+#    #+#             */
/*   Updated: 2015/01/22 18:59:56 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_atoi_ignored(char c)
{
	return (c == '\n'
	|| c == '\v'
	|| c == '\t'
	|| c == '\r'
	|| c == '\f'
	|| c == ' ');
}

int				ft_atoi(const char *str)
{
	unsigned long long	result;
	int					is_neg;
	int					i;

	while (is_atoi_ignored(*str))
		++str;
	result = 0;
	is_neg = str && *str == '-';
	i = str && (*str == '-' || *str == '+');
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (is_neg)
		return (-result);
	return (result);
}
