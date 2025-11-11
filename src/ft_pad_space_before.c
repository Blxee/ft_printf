/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_space_before.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:31:16 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:31:19 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pad_space_before(int fd, t_fmt fmt, int len)
{
	int	written;

	if (fmt.minus)
		return (0);
	if (fmt.handler == &ft_print_decimal
		|| fmt.handler == &ft_print_unsigned
		|| fmt.handler == &ft_print_hex_lower
		|| fmt.handler == &ft_print_hex_upper)
		if (fmt.zero)
			return (0);
	written = 0;
	while (fmt.width-- > len)
		written += write(fd, " ", 1);
	return (written);
}
