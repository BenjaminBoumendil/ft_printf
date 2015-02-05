/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:43:14 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/05 21:31:25 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "stdarg.h"
# include "../libft/includes/libft.h"

/*
** Defines
*/
# define PRINT_CHAR(v) data->char_print += v

/*
** Flags
*/
typedef struct	s_flag
{
	size_t		plus;
	size_t		minus;
	size_t		sharp;
	size_t		zero;
	size_t		space;
}				t_flag;

/*
** Printf
*/
typedef struct	s_data
{
	int			char_print;
	const char	*format;
	va_list		*va;
	t_flag		*flag;
}				t_data;
int				ft_printf(const char *restrict_format, ...);

/*
** Format
*/
typedef struct	s_token
{
	char		*str;
	void		(*f)(t_data *data);
}				t_token;

void			read_format(t_data *data);

/*
** Format tools
*/
void			ft_s(t_data *data);
void			ft_d(t_data *data);
void			ft_c(t_data *data);


#endif
