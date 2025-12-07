/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:13:39 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 15:00:05 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
create a table of pointers regrouping all given list's content in an allocated 
memory area, if second argument is different from 0, also delete list.
*/
void	**ft_lstjoin(t_list *begin_list, int deletion)
{
	void	**table;
	t_list	*temp;
	size_t	index;

	if (!begin_list)
		return (NULL);
	table = (void **)malloc(sizeof(void *) * (ft_lstsize(begin_list) + 1));
	if (!table)
		return (NULL);
	temp = begin_list;
	index = 0;
	while (temp)
	{
		table[index++] = temp->content;
		temp = temp->next;
	}
	table[index] = NULL;
	if (deletion)
		ft_lstclear(&begin_list, NULL);
	return (table);
}
