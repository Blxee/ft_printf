/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:31:31 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:31:33 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_apply_sign(int fd, t_fmt fmt, long nbr)
{
	if (fmt.plus && nbr >= 0)
		return (write(fd, "+", 1));
	else if (nbr < 0)
		return (write(fd, "-", 1));
	return (0);
}
