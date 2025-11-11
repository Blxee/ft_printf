/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:30:21 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:30:24 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(int fd, t_fmt fmt, va_list *ap)
{
	size_t	p;
	int		written;
	int		len;

	p = (size_t)va_arg(*ap, void *);
	written = 0;
	if (p == 0)
	{
		written += ft_putnstr_fd("(nil)", fd, -1);
		return (written);
	}
	len = ft_hexlen(p) + fmt.hash * 2;
	written += ft_pad_space_before(fd, fmt, len);
	written += ft_apply_sign(fd, fmt, 1);
	written += ft_apply_space(fd, fmt, 1);
	written += ft_putnstr_fd("0x", fd, -1);
	written += ft_puthex_fd(p, 0, fd);
	written += ft_pad_space_after(fd, fmt, len);
	return (written);
}
