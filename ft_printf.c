/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:20:41 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/28 10:25:43 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	return (ft_inner_dprintf(1, format, &ap));
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	return (ft_inner_dprintf(fd, format, &ap));
}

int		ft_inner_dprintf(int fd, const char *format, va_list *ap)
{
	t_fmt	fmt;
	int start;
	int len;
	int written;

	if (format == NULL || fd < 0)
		return (-1);
	written = 0;
	start = 0;
	len = 0;
	while (format[start + len] != '\0')
	{
		if (format[start + len] == '%')
		{
			written += ft_putnstr_fd((char *)format + start, fd, len);
			fmt = ft_parse_fmt((char *)format + start + len, &start);
			if (start == -1)
				return (-1);
			written += fmt.handler(fd, fmt, ap);
			start += len;
			len = 0;
		}
		else
			len++;
	}
	written += ft_putnstr_fd((char *)format + start, fd, -1);
	va_end(*ap);
	return (written);
}

int		ft_putnstr_fd(char *s, int fd, int n)
{
	int len;

	len = (int)ft_strlen(s);
	if (n < 0)
		n = len;
	else if (len < n)
		n = len;
	return (write(fd, s, n));
}

int ft_parse_specifier(t_fmt *fmt, char *str)
{
	static const char		*ident_keys = "cspdiuxX%";
	static const t_handler	ident_vals[] = {
		&ft_print_char,
		&ft_print_str,
		&ft_print_pointer,
		&ft_print_decimal,
		&ft_print_decimal,
		&ft_print_unsigned,
		&ft_print_hex_lower,
		&ft_print_hex_upper,
		&ft_print_percent,
	};
	int i;

	i = 0;
	while (ident_keys[i] != '\0')
	{
		if (ident_keys[i] == *str)
		{
			fmt->handler = ident_vals[i];
			return (1);
		}
		i++;
	}
	return (0);
}

int ft_contains(const void *arr, const void *elem,
				unsigned int elem_size, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (0 == ft_memcmp((unsigned char *)arr + i * elem_size, elem, elem_size))
			return (1);
		i++;
	}
	return (0);
}

int ft_parse_flags(t_fmt *fmt, char *str)
{
	static const t_flag s_flags[] = { MINUS, PLUS, ZERO, HASH, SPACE };
	int	i;
	int off;
	int	flag_idx;

	flag_idx = 0;
	off = 0;
	i = 0;
	while (str[i])
	{
		if (ft_contains(s_flags, &(unsigned long){str[i]}, sizeof(t_flag), 5))
		{
			if (!ft_contains(fmt->flags, &(unsigned long){str[i]}, sizeof(t_flag), 5))
				fmt->flags[flag_idx++] = str[i];
			off++;
		}
		else
			break ;
		i++;
	}
	return (off);
}

int ft_parse_width(t_fmt *fmt, char *str)
{
	int i;

	if (!ft_isdigit(str[0]))
		return (0);
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	fmt->width = ft_atoi(str);
	return (i);
}

int ft_parse_precision(t_fmt *fmt, char *str)
{
	int i;

	if (str[0] != '.' || !ft_isdigit(str[1]))
		return (0);
	i = 1;
	while (ft_isdigit(str[i]))
		i++;
	fmt->precision = ft_atoi(str + 1);
	return (i);
}

t_fmt	ft_parse_fmt(char *str, int *offset)
{
	t_fmt					fmt;
	int						off;

	ft_bzero(&fmt, sizeof(fmt));
	off = 1;
	off += ft_parse_flags(&fmt, str + off);
	off += ft_parse_width(&fmt, str + off);
	off += ft_parse_precision(&fmt, str + off);
	if (!ft_parse_specifier(&fmt, str + off))
	{
		*offset = -1;
		return (fmt);
	}
	off += 1;
	*offset += off;
	return (fmt);
}

int		ft_putlnbr_fd(long n, int fd)
{
	if (n < 0)
		return (write(fd, &(char){'-'}, 1) + ft_putlnbr_fd(-n, fd));
	if (n / 10 > 0)
		return (ft_putlnbr_fd(n / 10, fd) + write(fd, &(char){'0' + n % 10}, 1));
	return (write(fd, &(char){'0' + n % 10}, 1));
}

int		ft_puthex_fd(unsigned long n, int upper, int fd)
{
	static const char *const s_digits_lower = "0123456789abcdef";
	static const char *const s_digits_upper = "0123456789ABCDEF";
	const char *digits;

	digits = s_digits_lower;
	if (upper)
		digits = s_digits_upper;
	if (n / 16 > 0)
		return (ft_puthex_fd(n / 16, upper, fd) + write(fd, digits + n % 16, 1));
	return (write(fd, digits + n % 16, 1));
}

int		ft_print_char(int fd, t_fmt fmt, va_list *ap)
{
	char	chr;

	(void)fmt;
	chr = (char)va_arg(*ap, int);
	return (write(fd, &chr, 1));
}

int		ft_print_str(int fd, t_fmt fmt, va_list *ap)
{
	char	*str;
	int written;

	(void)fmt;
	str = va_arg(*ap, char *);
	written = 0;
	if (str == NULL)
	{
		written = ft_putnstr_fd("(null)", fd, -1);
		return (written);
	}
	written += ft_putnstr_fd(str, fd, -1);
	return (written);
}

int		ft_print_pointer(int fd, t_fmt fmt, va_list *ap)
{
	void *p;
	int written;

	(void)fmt;
	p = va_arg(*ap, void *);
	written = 0;
	if (p == NULL)
	{
		written += ft_putnstr_fd("(nil)", fd, -1);
		return (written);
	}
	written += ft_putnstr_fd("0x", fd, -1);
	written += ft_puthex_fd((unsigned long)p, 0, fd);
	return (written);
}

int		ft_print_decimal(int fd, t_fmt fmt, va_list *ap)
{
	int		nbr;

	(void)fmt;
	nbr = va_arg(*ap, int);
	return (ft_putlnbr_fd(nbr, fd));
}

int		ft_print_unsigned(int fd, t_fmt fmt, va_list *ap)
{
	unsigned int	nbr;

	(void)fmt;
	nbr = va_arg(*ap, unsigned int);
	return (ft_putlnbr_fd(nbr, fd));
}

int		ft_print_hex_lower(int fd, t_fmt fmt, va_list *ap)
{
	unsigned int nbr;

	(void)fmt;
	nbr = va_arg(*ap, unsigned int);
	return (ft_puthex_fd(nbr, 0, fd));
}

int		ft_print_hex_upper(int fd, t_fmt fmt, va_list *ap)
{
	unsigned int nbr;

	(void)fmt;
	nbr = va_arg(*ap, unsigned int);
	return (ft_puthex_fd(nbr, 1, fd));
}

int		ft_print_percent(int fd, t_fmt fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	return (write(fd, &(char){'%'}, 1));
}
