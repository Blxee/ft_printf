/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:21:17 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/23 09:23:15 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef enum s_type {
	CHAR,
	STRING,
	POINTER,
	DECIMAL,
	UNSIGNED,
	HEX_LOWER,
	HEX_UPPER,
	PRECENT,
}	t_type;

typedef enum t_length {
	BYTE,
	SHORT,
	INT,
	LONG,
	LONG_LONG,
}	t_length;

typedef struct s_fmt {
	// falgs
	// width
	// precision
	t_length length;
	t_type	type;
}	t_fmt;

typedef void	(*t_handler)(char *, t_fmt, va_list *);

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);

t_fmt	ft_parse_fmt(char *str, size_t *offset);

void	ft_str_extend_char(char *buf, t_fmt fmt, va_list *ap);
void	ft_str_extend_str(char *buf, t_fmt fmt, va_list *ap);
void	ft_str_extend_pointer(char *buf, t_fmt fmt, va_list *ap);
void	ft_str_extend_decimal(char *buf, t_fmt fmt, va_list *ap);
void	ft_str_extend_unsigned(char *buf, t_fmt fmt, va_list *ap);

#endif
