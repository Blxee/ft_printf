/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:30:52 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:30:54 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_width(t_fmt *fmt, char *str)
{
	int	i;

	if (!ft_isdigit(str[0]))
		return (0);
	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	fmt->width = ft_atoi(str);
	return (i);
}
