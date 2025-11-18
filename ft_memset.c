/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:03:42 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/05 12:17:25 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast_s;
	unsigned char	cast_c;

	cast_s = (unsigned char *)s;
	cast_c = (unsigned char)c;
	while (n--)
		*cast_s++ = cast_c;
	return (s);
}
