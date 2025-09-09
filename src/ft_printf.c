/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <atahiri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 23:23:27 by atahiri-          #+#    #+#             */
/*   Updated: 2025/09/06 16:09:18 by blxee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
t_token *ft_parse_conversion(char *str, int *offset)
{
	t_token *result;
	static char *specifier_keys = "sSpdDioOuUxXcC";
	static t_specifier specifier_values[] = {STRING, STRING, CHAR, CHAR, DECIMAL, DECIMAL};
	int i;
	
	result = malloc(sizeof(*result));
	i = 0;
	while (specifier_keys[i])
	{
		if (str[1] == specifier_keys[i])
		{
			result->specifier = specifier_values[i];
			&offset += 2;
			break ;
		}
		i++;
	}
	return (result);
}
*/

int ft_printf(char *format, ...)
{
	va_list args;
	int i;
	int j;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		j = 0;
		while (format[i + j] && format[i + j] != '%')
			j++;
		if (j > 0)
		{
			ft_putnstr(format + i, j);
		}
		if (format[i + j])
		{
			if (format[i + j + 1] == 's')
				ft_putstr(va_arg(args, char *));
			else if (format[i + j + 1] == 'd')
				ft_putnbr(va_arg(args, int));
			j += 2;
		}
		i += j;
	}
	va_end(args);
	return (0);
}
