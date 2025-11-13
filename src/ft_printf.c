/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:20:41 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/13 08:27:07 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_format(t_fields *fields)
{
	fields->written += ft_putnstr_fd((char *)fields->format + fields->start,
			fields->fd, fields->len);
	fields->fmt = ft_parse_fmt((char *)fields->format
			+ fields->start + fields->len, &fields->start);
	if (fields->fmt.handler == NULL)
	{
		fields->written += write(fields->fd, "%", 1);
		fields->len++;
	}
	else
		fields->written += fields->fmt.handler(fields->fd,
				fields->fmt, fields->ap);
	fields->start += fields->len;
	fields->len = 0;
}

static int	ft_inner_dprintf(int fd, const char *format, va_list *ap)
{
	t_fields	fields;

	if (format == NULL || write(fd, NULL, 0) < 0)
		return (-1);
	fields.format = format;
	fields.written = 0;
	fields.start = 0;
	fields.len = 0;
	fields.ap = ap;
	fields.fd = fd;
	while (format[fields.start + fields.len] != '\0')
	{
		if (format[fields.start + fields.len] == '%')
		{
			if (format[fields.start + fields.len + 1] == '\0')
				return (-1);
			ft_handle_format(&fields);
		}
		else
			fields.len++;
	}
	fields.written += ft_putnstr_fd((char *)format + fields.start, fd, -1);
	return (fields.written);
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
