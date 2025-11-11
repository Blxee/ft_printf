/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:30:14 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:30:18 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(int fd, t_fmt fmt, va_list *ap)
{
	char	*str;
	int		written;
	size_t	len;

	(void)fmt;
	str = va_arg(*ap, char *);
	written = 0;
	if (str == NULL)
		return (ft_putnstr_fd("(null)", fd, -1));
	len = ft_strlen(str);
	if (fmt.precision >= 0 && (size_t)fmt.precision < len)
		len = fmt.precision;
	written += ft_pad_space_before(fd, fmt, len);
	written += ft_putnstr_fd(str, fd, len);
	written += ft_pad_space_after(fd, fmt, written);
	return (written);
}
