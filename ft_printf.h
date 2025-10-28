/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:21:17 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/26 20:56:11 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_fmt t_fmt;

typedef int	(*t_handler)(int fd, t_fmt, va_list *);

typedef enum e_flag {
	MINUS = '-',
	PLUS = '+',
	ZERO = '0',
	HASH = '#',
	SPACE = ' ',
}	t_flag;

typedef struct s_fmt {
	t_flag	flags[5];
	int		width;
	int		precision;
	t_handler handler;
}	t_fmt;

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_inner_dprintf(int fd, const char *format, va_list *ap);

int		ft_putnstr_fd(char *s, int fd, int n);
t_fmt	ft_parse_fmt(char *str, int *offset);
int		ft_puthex_fd(unsigned long n, int upper, int fd);
int		ft_putlnbr_fd(long n, int fd);

int		ft_print_char(int fd, t_fmt fmt, va_list *ap);
int		ft_print_str(int fd, t_fmt fmt, va_list *ap);
int		ft_print_pointer(int fd, t_fmt fmt, va_list *ap);
int		ft_print_decimal(int fd, t_fmt fmt, va_list *ap);
int		ft_print_unsigned(int fd, t_fmt fmt, va_list *ap);
int		ft_print_hex_lower(int fd, t_fmt fmt, va_list *ap);
int		ft_print_hex_upper(int fd, t_fmt fmt, va_list *ap);
int		ft_print_percent(int fd, t_fmt fmt, va_list *ap);

#endif
