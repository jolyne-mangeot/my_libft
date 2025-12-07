/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:20:55 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:58:44 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
copy an input length of memory from a source to a destination, making sure 
memory overlap doesn't duplicate or erase data, returns pointer to destination.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cast_dest;
	unsigned char	*cast_src;

	cast_dest = (unsigned char *)dest;
	cast_src = (unsigned char *)src;
	if ((size_t)dest > (size_t)src)
		while (n--)
			*(cast_dest + n) = *(cast_src + n);
	else
		while (n--)
			*cast_dest++ = *cast_src++;
	return (dest);
}
