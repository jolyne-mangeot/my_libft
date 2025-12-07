/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:13:39 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:40:37 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		table[index++] = temp->content;
	table[index] = NULL;
	if (deletion)
		ft_lstclear(&begin_list, &free);
	return (table);
}
