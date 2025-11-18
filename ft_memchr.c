/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:50:15 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/14 18:03:32 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cast_s;
	unsigned char	cast_c;
	size_t			index;

	if (!s)
		return (NULL);
	cast_s = (unsigned char *)s;
	cast_c = (unsigned char)c;
	index = 0;
	while (index < n)
		if (cast_s[index++] == cast_c)
			return (cast_s + index - 1);
	return (NULL);
}
