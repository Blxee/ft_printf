/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:20:41 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/13 07:54:04 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_inner_dprintf(int fd, const char *format, va_list *ap)
{
	t_fmt	fmt;
	int		start;
	int		len;
	int		written;

	if (format == NULL || write(fd, NULL, 0) < 0)
		return (-1);
	written = 0;
	start = 0;
	len = 0;
	while (format[start + len] != '\0')
	{
		if (format[start + len] == '%')
		{
			if (format[start + len + 1] == '\0')
				return (-1);
			written += ft_putnstr_fd((char *)format + start, fd, len);
			fmt = ft_parse_fmt((char *)format + start + len, &start);
			if (fmt.handler == NULL)
			{
				written += write(fd, "%", 1);
				len++;
			}
			else
				written += fmt.handler(fd, fmt, ap);
			start += len;
			len = 0;
		}
		else
			len++;
	}
	return (written += ft_putnstr_fd((char *)format + start, fd, -1), written);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_inner_dprintf(1, format, &ap);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_inner_dprintf(fd, format, &ap);
	va_end(ap);
	return (ret);
}
