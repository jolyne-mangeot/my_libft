/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:29:58 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:58:59 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copy on an input maximum length a string of characters from a source to a 
destination and returns the amount of concerned bytes.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	if (src_len >= size)
	{
		ft_memcpy(dst, src, size);
		dst[size - 1] = 0;
	}
	else if (size > 0)
	{
		ft_memcpy(dst, src, src_len);
		dst[src_len] = 0;
	}
	return (src_len);
}
