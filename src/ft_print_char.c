/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:30:48 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:30:50 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int fd, t_fmt fmt, va_list *ap)
{
	char	chr;
	int		written;

	written = 0;
	chr = (char)va_arg(*ap, int);
	written += ft_pad_space_before(fd, fmt, 1);
	written += write(fd, &chr, 1);
	written += ft_pad_space_after(fd, fmt, 1);
	return (written);
}
