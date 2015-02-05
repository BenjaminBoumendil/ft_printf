/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:17:45 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/03 18:41:59 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	c;

	c = NNB(n);
	if (n < 0)
		ft_putchar('-');
	if (c >= 10)
	{
		ft_putnbr(c / 10);
		ft_putnbr(c % 10);
	}
	else
		ft_putchar(48 + c);
}
