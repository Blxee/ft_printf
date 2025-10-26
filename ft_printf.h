/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:21:17 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/26 08:02:02 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_fmt t_fmt;

typedef int	(*t_handler)(int fd, t_fmt, va_list *);

typedef struct s_fmt {
	// flags
	// width
	t_handler handler;
}	t_fmt;

int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

void	ft_putnstr_fd(char *s, int fd, int n);
t_fmt	ft_parse_fmt(char *str, int *offset);

int		ft_print_char(int fd, t_fmt fmt, va_list *ap);
int		ft_print_str(int fd, t_fmt fmt, va_list *ap);
int		ft_print_pointer(int fd, t_fmt fmt, va_list *ap);
int		ft_print_decimal(int fd, t_fmt fmt, va_list *ap);
int		ft_print_unsigned(int fd, t_fmt fmt, va_list *ap);
int		ft_print_hex_lower(int fd, t_fmt fmt, va_list *ap);
int		ft_print_hex_upper(int fd, t_fmt fmt, va_list *ap);
int		ft_print_percent(int fd, t_fmt fmt, va_list *ap);

#endif
