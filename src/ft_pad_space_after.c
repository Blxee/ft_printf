/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_space_after.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:31:21 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:31:23 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pad_space_after(int fd, t_fmt fmt, int len)
{
	int	written;

	written = 0;
	if (fmt.minus)
		while (fmt.width-- > len)
			written += write(fd, " ", 1);
	return (written);
}
