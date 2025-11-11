/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:31:03 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:31:05 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
