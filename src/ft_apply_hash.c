/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:29:34 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:29:49 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_apply_hash(int fd, t_fmt fmt, unsigned long nbr)
{
	if (fmt.hash && nbr != 0)
	{
		if (fmt.handler == &ft_print_hex_lower)
			return (write(fd, "0x", 2));
		else
			return (write(fd, "0X", 2));
	}
	return (0);
}
