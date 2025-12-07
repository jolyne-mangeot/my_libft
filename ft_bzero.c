/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:50:01 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:58:04 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
replace input amount of bytes by zeroes, no return value.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*cast_s;

	if (s)
	{
		cast_s = (unsigned char *)s;
		while (n--)
			*(cast_s + n) = 0;
	}
}
