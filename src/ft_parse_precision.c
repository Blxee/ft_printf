/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:30:59 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:31:01 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_precision(t_fmt *fmt, char *str)
{
	int	i;

	fmt->precision = -1;
	if (str[0] != '.' || !ft_isdigit(str[1]))
		return (0);
	i = 1;
	while (ft_isdigit(str[i]))
		i++;
	fmt->precision = ft_atoi(str + 1);
	return (i);
}
