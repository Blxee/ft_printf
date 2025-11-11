/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:31:12 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:31:14 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pad_zero(int fd, t_fmt fmt, int len)
{
	int	written;

	written = 0;
	while (fmt.precision == -1 && !fmt.minus && fmt.zero && fmt.width-- > len)
		written += write(fd, "0", 1);
	return (written);
}
