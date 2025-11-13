/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:13:21 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/25 08:04:51 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*memory;
	size_t			i;
	size_t			product;

	product = nmemb * size;
	if (size != 0 && product / size != nmemb)
		return (NULL);
	memory = (unsigned char *)malloc(product);
	if (memory == NULL)
		return (NULL);
	i = 0;
	while (i < product)
	{
		memory[i] = 0;
		i++;
	}
	return ((void *)memory);
}
