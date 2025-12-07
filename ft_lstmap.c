/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:44:47 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 14:04:06 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
return a chained list created from the result of an input function applied to 
every content of a source list.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	map_list = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&map_list, del);
			return (NULL);
		}
		ft_lstadd_back(&map_list, new_node);
		lst = lst->next;
	}
	return (map_list);
}
