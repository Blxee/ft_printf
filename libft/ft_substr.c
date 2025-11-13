/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:56:36 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/21 14:13:26 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	size_t	i;
	char	*sub;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	sub_len = s_len;
	if (len < sub_len)
		sub_len = len;
	sub = ft_calloc(sizeof(char), sub_len + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < sub_len && start < s_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
