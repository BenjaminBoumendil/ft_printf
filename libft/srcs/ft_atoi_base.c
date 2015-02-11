/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 21:16:01 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/10 21:58:10 by bboumend         ###   ########.fr       */
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

int				ft_atoi_base(const char *str, int base)
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
		result = result * base + (str[i++] - '0');
	if (is_neg)
		return (-result);
	return (result);
}