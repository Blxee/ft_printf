/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:29:54 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:29:57 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_hexlen(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_putlnbr_fd(long n, int fd)
{
	if (n < 0)
		return (ft_putlnbr_fd(-n, fd));
	if (n / 10 > 0)
		return (ft_putlnbr_fd(n / 10, fd)
			+ write(fd, &(char){'0' + n % 10}, 1));
	return (write(fd, &(char){'0' + n % 10}, 1));
}

int	ft_puthex_fd(unsigned long n, int upper, int fd)
{
	static const char *const	s_digits_lower = "0123456789abcdef";
	static const char *const	s_digits_upper = "0123456789ABCDEF";
	const char					*digits;

	digits = s_digits_lower;
	if (upper)
		digits = s_digits_upper;
	if (n / 16 > 0)
		return (ft_puthex_fd(n / 16, upper, fd)
			+ write(fd, digits + n % 16, 1));
	return (write(fd, digits + n % 16, 1));
}
