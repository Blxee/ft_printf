/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:27:49 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/21 16:25:58 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	nbr[12];
	long	num;
	int		is_first_digit;

	if (fd < 0)
		return ;
	num = (long)n;
	i = 0;
	if (num < 0)
		num = -num;
	is_first_digit = 1;
	while (num > 0 || is_first_digit)
	{
		nbr[i++] = '0' + num % 10;
		is_first_digit = 0;
		num /= 10;
	}
	if (n < 0)
		nbr[i++] = '-';
	i--;
	while (i >= 0)
		write(fd, nbr + i--, 1);
}
