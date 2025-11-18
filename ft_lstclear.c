/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:26:20 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/18 21:29:32 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_node;

	if (lst)
	{
		while (*lst)
		{
			del((*lst)->content);
			temp_node = (*lst)->next;
			free(*lst);
			*lst = temp_node;
		}
	}
}
