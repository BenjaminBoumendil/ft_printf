/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboumend <bboumend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:43:14 by bboumend          #+#    #+#             */
/*   Updated: 2015/02/16 16:26:55 by bboumend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "stdarg.h"
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include <wchar.h>

/*
** Defines
*/
# define COUNT_CHAR(v) data->char_print += v

typedef enum	e_bool
{
	false,
	true
}				t_bool;

# define BOOL typedef t_bool bool

BOOL;

/*
** Flags
*/
typedef struct	s_flag
{
	bool		plus;
	bool		minus;
	bool		sharp;
	bool		zero;
	bool		space;
}				t_flag;

typedef struct	s_modifier
{
	bool		hh;
	bool		h;
	bool		l;
	bool		ll;
	bool		j;
	bool		z;
}				t_modifier;

typedef struct	s_flags
{
	char		*str;
	bool		*flag;
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
	char		opt;
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
void			handle_padding_with_no_option(t_data *data);

/*
** Format tools
*/
void			opt_s(t_data *data);
void			opt_S(t_data *data);
void			opt_d(t_data *data);
void			opt_D(t_data *data);
void			opt_c(t_data *data);
void			opt_C(t_data *data);
void			opt_o(t_data *data);
void			opt_O(t_data *data);
void			opt_u(t_data *data);
void			opt_U(t_data *data);
void			opt_p(t_data *data);
void			opt_per(t_data *data);
void			opt_x(t_data *data);
void			opt_X(t_data *data);
char			*convert_wchar(t_data *data, int c);

/*
** Display
*/
void			display(t_data *data, char *str);

/*
** Special cases handling
*/
typedef struct	s_handle
{
	char		*tokens;
	int			(*f)(t_data *data, char **str);
}				t_handle;
int				handle_special_cases(t_data *data, char **str);

void			neg_numbertoken_zeroflag(char **str);
void			handle_optc_padding(char c, size_t min_width);

#endif
