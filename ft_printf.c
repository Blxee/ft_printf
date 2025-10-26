/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:20:41 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/26 10:51:45 by atahiri-         ###   ########.fr       */
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

	if (format == NULL)
		return (-1);
	start = 0;
	len = 0;
	while (format[start + len] != '\0')
	{
		if (format[start + len] == '%')
		{
			ft_putnstr_fd((char *)format + start, fd, len);
			fmt = ft_parse_fmt((char *)format + start + len, &start);
			fmt.handler(fd, fmt, ap);
			start += len;
		}
		else
			len++;
	}
	ft_putstr_fd((char *)format + start, fd);
	va_end(*ap);
	return (0);
}

void	ft_putnstr_fd(char *s, int fd, int n)
{
	write(fd, s, n);
}

t_fmt	ft_parse_fmt(char *str, int *offset)
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
	t_fmt					fmt;
	int						i;
	int						off;

	off = 1;
	i = 0;
	ft_bzero(&fmt, sizeof(fmt));
	while (ident_keys[i] != '\0')
	{
		if (ident_keys[i] == str[off])
		{
			fmt.handler = ident_vals[i];
			break ;
		}
		i++;
	}
	off++;
	*offset += off;
	return (fmt);
}

int		ft_print_char(int fd, t_fmt fmt, va_list *ap)
{
	char	chr;

	(void)fmt;
	chr = (char)va_arg(*ap, int);
	ft_putchar_fd(chr, fd);
	return (1);
}

int		ft_print_str(int fd, t_fmt fmt, va_list *ap)
{
	char	*str;

	(void)fmt;
	str = va_arg(*ap, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

void	ft_puthex_fd(unsigned long n, int upper, int fd)
{
	static const char *const s_digits_lower = "0123456789abcdef";
	static const char *const s_digits_upper = "0123456789ABCDEF";
	const char *digits;

	digits = s_digits_lower;
	if (upper)
		digits = s_digits_upper;
	if (fd < 0)
		return ;
	if (n / 16 > 0)
		ft_puthex_fd(n / 16, upper, fd);
	write(fd, digits + n % 16, 1);
}

int		ft_print_pointer(int fd, t_fmt fmt, va_list *ap)
{
	void *p;

	(void)fmt;
	p = va_arg(*ap, void *);
	if (p == NULL)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	ft_putstr_fd("0x", fd);
	ft_puthex_fd((unsigned long)p, 0, fd);
	return (-1);
}

int		ft_print_decimal(int fd, t_fmt fmt, va_list *ap)
{
	int		nbr;

	(void)fmt;
	nbr = va_arg(*ap, int);
	ft_putnbr_fd(nbr, fd);
	return (-1);
}

int		ft_print_unsigned(int fd, t_fmt fmt, va_list *ap)
{
	unsigned int	nbr;

	(void)fmt;
	nbr = va_arg(*ap, unsigned int);
	ft_putnbr_fd(nbr, fd);
	return (-1);
}

int		ft_print_hex_lower(int fd, t_fmt fmt, va_list *ap)
{
	unsigned int nbr;

	(void)fmt;
	nbr = va_arg(*ap, unsigned int);
	ft_puthex_fd(nbr, 0, fd);
	return (-1);
}

int		ft_print_hex_upper(int fd, t_fmt fmt, va_list *ap)
{
	unsigned int nbr;

	(void)fmt;
	nbr = va_arg(*ap, unsigned int);
	ft_puthex_fd(nbr, 1, fd);
	return (-1);
}

int		ft_print_percent(int fd, t_fmt fmt, va_list *ap)
{
	(void)fmt;
	(void)ap;
	ft_putchar_fd('%', fd);
	return (-1);
}
