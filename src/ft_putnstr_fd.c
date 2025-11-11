/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:30:04 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:30:07 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr_fd(char *s, int fd, int n)
{
	int	len;

	len = (int)ft_strlen(s);
	if (n < 0)
		n = len;
	else if (len < n)
		n = len;
	return (write(fd, s, n));
}
