/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <atahiri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:23:27 by atahiri-          #+#    #+#             */
/*   Updated: 2025/09/24 16:07:51 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_format(t_string *const buffer, const char *const format, va_list *const args)
{
	static const char map_keys[] = { 's', 'c', 'd', 'x', 'o', 'b', 'f' };
	static void (*const map_vals[])(t_string *const, t_format *, va_list *) = {
		ft_str_add_str,
		ft_str_add_char,
	};
	static const int map_len = 7;
	t_format fmt;
	int i;

	i = 0;
	while (i < map_len)
	{
		if (format[1] == map_keys[i])
			map_vals[i](buffer, &fmt, args);
		i++;
	}
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
	mem_free_all();
	return (0);
}
