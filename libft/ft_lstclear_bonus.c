/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atahiri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 09:36:10 by atahiri-          #+#    #+#             */
/*   Updated: 2025/10/15 09:40:37 by atahiri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next;

	if (lst == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		if (del != NULL)
			del(node->content);
		next = node->next;
		free(node);
		node = next;
	}
	*lst = NULL;
}
