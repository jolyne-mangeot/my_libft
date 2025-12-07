/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:56:02 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:55:17 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
compare two memory areas on an input length until bytes differ, returning the 
difference of value of byte1 - byte2, otherwise 0.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;

	if (!s1 || !s2)
		return (0);
	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	while (n--)
		if (*cast_s1++ != *cast_s2++)
			return (*(cast_s1 - 1) - *(cast_s2 - 1));
	return (0);
}
