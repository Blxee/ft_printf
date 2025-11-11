/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:21:17 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 10:00:45 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_fmt	t_fmt;

typedef int				(*t_handler)(int fd, t_fmt, va_list *);

typedef enum e_flag {
	MINUS,
	PLUS,
	ZERO,
	HASH,
	SPACE,
}	t_flag;

typedef struct s_fmt {
	union {
		int	flags[5];
		struct {
			int	minus;
			int	plus;
			int	zero;
			int	hash;
			int	space;
		};
	};
	int			width;
	int			precision;
	t_handler	handler;
}	t_fmt;

int			ft_printf(const char *format, ...);
int			ft_dprintf(int fd, const char *format, ...);

t_fmt		ft_parse_fmt(char *str, int *offset);
int			ft_putnstr_fd(char *s, int fd, int n);
int			ft_parse_specifier(t_fmt *fmt, char *str);
int			ft_parse_flags(t_fmt *fmt, char *str);
int			ft_parse_width(t_fmt *fmt, char *str);
int			ft_parse_precision(t_fmt *fmt, char *str);

int			ft_intlen(long n);
int			ft_hexlen(unsigned long n);
int			ft_putlnbr_fd(long n, int fd);
int			ft_puthex_fd(unsigned long n, int upper, int fd);

int			ft_apply_sign(int fd, t_fmt fmt, long nbr);
int			ft_apply_space(int fd, t_fmt fmt, long nbr);
int			ft_apply_precision(int fd, t_fmt fmt, int len);
int			ft_apply_hash(int fd, t_fmt fmt, unsigned long nbr);
int			ft_pad_space_before(int fd, t_fmt fmt, int len);
int			ft_pad_zero(int fd, t_fmt fmt, int len);
int			ft_pad_space_after(int fd, t_fmt fmt, int len);

int			ft_print_char(int fd, t_fmt fmt, va_list *ap);
int			ft_print_str(int fd, t_fmt fmt, va_list *ap);
int			ft_print_decimal(int fd, t_fmt fmt, va_list *ap);
int			ft_print_unsigned(int fd, t_fmt fmt, va_list *ap);
int			ft_print_pointer(int fd, t_fmt fmt, va_list *ap);
int			ft_print_hex_lower(int fd, t_fmt fmt, va_list *ap);
int			ft_print_hex_upper(int fd, t_fmt fmt, va_list *ap);
int			ft_print_percent(int fd, t_fmt fmt, va_list *ap);

#endif
