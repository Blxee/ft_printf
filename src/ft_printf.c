/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <atahiri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:23:27 by atahiri-          #+#    #+#             */
/*   Updated: 2025/09/17 14:32:08 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_format(t_string *const buffer, const char *const format, va_list *const args)
{
	// mem_alloc(sizeof(t_format));
	if (format[1] == 's')
		ft_str_add_str(buffer, NULL, args);
	else if (format[1] == 'c')
		ft_str_add_char(buffer, NULL, args);

	return (2);
}

int ft_printf(char *format, ...)
{
	va_list args;
	t_string *buffer;
	int i;
	int j;

	va_start(args, format);
	buffer = ft_str_create();
	i = 0;
	while (format[i])
	{
		j = 0;
		while (format[i + j] && format[i + j] != '%')
			j++;
		if (j > 0)
		{
			ft_str_extend(buffer, format + i, j);
		}
		if (format[i + j])
			j += ft_print_format(buffer, format + i + j, &args);
		i += j;
	}
	ft_putstr(buffer->str);
	ft_str_free(&buffer);
	va_end(args);
	return (0);
}
