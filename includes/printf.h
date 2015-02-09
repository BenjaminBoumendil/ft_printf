/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochase <ochase@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:43:14 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/09 13:41:00 by ochase           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "stdarg.h"
# include "libft.h"

/*
** Defines
*/
# define COUNT_CHAR(v) data->char_print += v
# define BOOL t_bool

typedef enum	e_bool
{
	false,
	true
}				t_bool;

/*
** Flags
*/
typedef struct	s_flag
{
	BOOL		plus;
	BOOL		minus;
	BOOL		sharp;
	BOOL		zero;
	BOOL		space;
}				t_flag;

typedef struct	s_modifier
{
	BOOL		hh;
	BOOL		h;
	BOOL		ll;
	BOOL		l;
	BOOL		j;
	BOOL		z;
}				t_modifier;

typedef struct	s_flags
{
	char		*str;
	BOOL		*flag;
}				t_flags;

/*
** Printf
*/
typedef struct	s_data
{
	int			char_print;
	const char	*format;
	va_list		*va;
	t_flag		*flag;
	t_modifier	*modifier;
	size_t		min_width;
	size_t		precision;
}				t_data;

int				ft_printf(const char *restrict_format, ...);
void			read_format(t_data *data);

/*
** Parser
*/
typedef struct	s_token
{
	char		c;
	void		(*f)(t_data *data);
}				t_token;

void			parse_flags(t_data *data);
void			parse_width(t_data *data);
void			parse_precision(t_data *data);
void			parse_modifier(t_data *data);
void			parse_token(t_data *data);

size_t			get_integer(t_data *data);

/*
** Format tools
*/
void			opt_s(t_data *data);
void			opt_d(t_data *data);
void			opt_c(t_data *data);

/*
** Display
*/
void			display(t_data *data, char *str);

#endif
