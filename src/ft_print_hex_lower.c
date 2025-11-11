/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:30:38 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:30:40 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_lower(int fd, t_fmt fmt, va_list *ap)
{
	unsigned int	nbr;
	int				len;
	int				written;

	written = 0;
	nbr = va_arg(*ap, unsigned int);
	if (fmt.precision == 0 && nbr == 0)
		return (0);
	len = ft_hexlen((unsigned long)nbr);
	if (fmt.precision > len)
		len = fmt.precision;
	written += ft_pad_space_before(fd, fmt, len);
	written += ft_apply_hash(fd, fmt, (unsigned long)nbr);
	written += ft_apply_precision(fd, fmt, ft_hexlen((unsigned long)nbr));
	written += ft_pad_zero(fd, fmt, len);
	written += ft_puthex_fd(nbr, 0, fd);
	written += ft_pad_space_after(fd, fmt, written);
	return (written);
}
