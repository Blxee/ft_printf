/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:31:35 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:31:39 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_apply_precision(int fd, t_fmt fmt, int len)
{
	int	written;

	written = 0;
	while (fmt.precision-- > len)
		written += write(fd, "0", 1);
	return (written);
}
