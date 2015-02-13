/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 21:16:01 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/13 17:52:29 by bboumend         ###   ########.fr       */
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

int				ft_atoi_base(const char *str, const char *base)
{
	unsigned long long	result;
	int					is_neg;
	int					i;
	size_t				base_len;
	char				*c;

	base_len = ft_strlen(base);
	while (is_atoi_ignored(*str))
		++str;
	result = 0;
	is_neg = str && *str == '-';
	i = str && (*str == '-' || *str == '+');
	while (str[i] && (c = ft_strchr(base, str[i++])))
		result = result * base_len + c - base;
	if (is_neg)
		return (-result);
	return (result);
}
