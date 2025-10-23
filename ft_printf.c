/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:20:41 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/23 09:24:34 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_handler	g_handlers[] = {
	&ft_str_extend_char,
	&ft_str_extend_str,
	&ft_str_extend_pointer,
	&ft_str_extend_decimal,
	&ft_str_extend_decimal,
	&ft_str_extend_unsigned,
};

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list					ap;
	size_t					start;
	size_t					len;
	t_fmt					fmt;

	va_start(ap, format);
	start = 0;
	len = 0;
	while (format[start + len] != '\0')
	{
		if (format[start + len] == '%')
		{
			ft_strlcat(str, format + start, len + 1);
			start = len;
			fmt = ft_parse_fmt(((char *)format) + start, &start);
			g_handlers[fmt.type](str, fmt, &ap);
			len = 0;
		}
		else
			len++;
	}
	ft_strlcat(str, format + start, len + 1);
	va_end(ap);
	return (0);
}

t_fmt	ft_parse_fmt(char *str, size_t *offset)
{
	static const char		*s_types = "cspdiuxX%";
	static const char		*s_lengths[] = {"hh", "h", "", "l", "ll", NULL};
	t_fmt					fmt;
	size_t					i;
	size_t					len;

	str++;
	i = 0;
	while (s_lengths[i] != NULL)
	{
		len = ft_strlen(s_lengths[i]);
		if (ft_strncmp(s_lengths[i], str, len) == 0)
		{
			fmt.length = i;
			break ;
		}
		i++;
	}
	str += len;
	i = 0;
	while (s_types[i] != '\0')
	{
		if (s_types[i] == *str)
		{
			fmt.type = i;
			break ;
		}
		i++;
	}
	*offset += 2;
	return (fmt);
}

void	ft_str_extend_char(char *buf, t_fmt fmt, va_list *ap)
{
	char	chr[2];

	(void)fmt;
	chr[0] = (char)va_arg(*ap, int);
	chr[1] = '\0';
	ft_strlcat(buf, chr, 1024);
}

void	ft_str_extend_str(char *buf, t_fmt fmt, va_list *ap)
{
	char	*str;

	(void)fmt;
	str = va_arg(*ap, char *);
	ft_strlcat(buf, str, 1024);
}

void	ft_str_extend_pointer(char *buf, t_fmt fmt, va_list *ap)
{
	(void)buf;
	(void)fmt;
	(void)ap;
}

void	ft_str_extend_decimal(char *buf, t_fmt fmt, va_list *ap)
{
	long long	nbr;
	char		*str;

	nbr = 0;
	if (BYTE == fmt.length)
		nbr = va_arg(*ap, int);
	if (SHORT == fmt.length)
		nbr = va_arg(*ap, int);
	if (INT == fmt.length)
		nbr = va_arg(*ap, int);
	// if (LONG == fmt.length)
	// 	nbr = va_arg(*ap, long);
	// if (LONG_LONG == fmt.length)
	// 	nbr = va_arg(*ap, long long);

	str = ft_itoa(nbr);
	ft_strlcat(buf, str, 1024);
	free(str);
}

void	ft_str_extend_unsigned(char *buf, t_fmt fmt, va_list *ap)
{
	unsigned long long	nbr;
	char				*str;

	nbr = 0;
	if (BYTE == fmt.length)
		nbr = va_arg(*ap, unsigned int);
	if (SHORT == fmt.length)
		nbr = va_arg(*ap, unsigned int);
	// if (INT == fmt.length)
	// 	nbr = va_arg(*ap, unsigned int);
	// if (LONG == fmt.length)
	// 	nbr = va_arg(*ap, long);
	// if (LONG_LONG == fmt.length)
	// 	nbr = va_arg(*ap, long long);

	str = ft_itoa(nbr);
	ft_strlcat(buf, str, 1024);
	free(str);
}
