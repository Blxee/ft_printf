/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:20:41 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/25 08:39:39 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	t_fmt	fmt;
	int start;
	int len;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	start = 0;
	len = 0;
	while (format[start + len] != '\0')
	{
		if (format[start + len] == '%')
		{
			ft_putnstr_fd((char *)format + start, fd, len);
			fmt = ft_parse_fmt((char *)format + start + len, &start);
			fmt.handler(fd, fmt, &ap);
			start += len;
		}
		else
			len++;
	}
	ft_putstr_fd((char *)format + start, fd);
	va_end(ap);
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
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int		ft_print_pointer(int fd, t_fmt fmt, va_list *ap)
{
	(void)fd;
	(void)fmt;
	(void)ap;
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
	unsigned long long	nbr;

	(void)fmt;
	nbr = va_arg(*ap, unsigned int);
	ft_putnbr_fd(nbr, fd);
	return (-1);
}
