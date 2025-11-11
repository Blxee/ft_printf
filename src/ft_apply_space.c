/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:31:26 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:31:29 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_apply_space(int fd, t_fmt fmt, long nbr)
{
	if (fmt.space && !fmt.plus && nbr >= 0)
		return (write(fd, " ", 1));
	return (0);
}
