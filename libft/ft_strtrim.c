/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:13:59 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/23 18:15:42 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(const char *set, const char c)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_idx;
	size_t	end_idx;
	size_t	len;
	char	*new;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_idx = 0;
	while (ft_contains(set, s1[start_idx]))
		start_idx++;
	end_idx = ft_strlen(s1) - 1;
	while (end_idx >= start_idx && ft_contains(set, s1[end_idx]))
		end_idx--;
	len = end_idx - start_idx + 2;
	new = malloc(len);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1 + start_idx, len);
	return (new);
}
