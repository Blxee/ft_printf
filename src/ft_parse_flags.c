/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:31:07 by atahiri-          #+#    #+#             */
/*   Updated: 2025/11/11 09:31:09 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flags(t_fmt *fmt, char *str)
{
	static char	*flags = "-+0# ";
	int			i;
	char		*found;
	int			off;

	off = 0;
	i = 0;
	while (str[i])
	{
		found = ft_strchr(flags, str[i]);
		if (found)
		{
			fmt->flags[found - flags] = 1;
			off++;
		}
		else
			break ;
		i++;
	}
	return (off);
}
