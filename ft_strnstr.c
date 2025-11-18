/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:21:35 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/14 18:05:29 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	little_len;

	if (!little || !little[0])
		return ((char *)big);
	little_len = ft_strlen(little);
	if (!big || !len || little_len > len)
		return (NULL);
	index = 0;
	while (index <= len - little_len && big[index])
		if (big[index++] == little[0])
			if (ft_strncmp(big + index - 1, little, little_len) == 0)
				return ((char *)big + index - 1);
	return (NULL);
}
