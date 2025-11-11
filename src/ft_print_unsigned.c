/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:30:09 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:30:12 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(int fd, t_fmt fmt, va_list *ap)
{
	unsigned int		nbr;
	int					len;
	int					written;

	written = 0;
	nbr = va_arg(*ap, int);
	if (fmt.precision == 0 && nbr == 0)
		return (0);
	len = ft_intlen(nbr);
	if (fmt.precision > len)
		len = fmt.precision;
	written += ft_pad_space_before(fd, fmt, len);
	written += ft_apply_precision(fd, fmt, ft_intlen(nbr));
	written += ft_pad_zero(fd, fmt, len);
	written += ft_putlnbr_fd(nbr, fd);
	written += ft_pad_space_after(fd, fmt, written);
	return (written);
}
