/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:38:59 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/17 08:26:27 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

char	*ft_itoa(int n)
{
	size_t	i;
	char	*nbr;
	long	num;
	int		is_first_digit;

	nbr = malloc(12);
	if (nbr == NULL)
		return (NULL);
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
	nbr[i] = '\0';
	ft_strrev(nbr);
	return (nbr);
}
