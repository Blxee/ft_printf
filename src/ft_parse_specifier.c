/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:30:56 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:30:57 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_specifier(t_fmt *fmt, char *str)
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
	int						i;

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
