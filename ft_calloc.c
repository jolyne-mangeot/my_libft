/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:05:00 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/14 18:06:25 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	factor_product;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	else if (size > __SIZE_MAX__ / nmemb)
		return (NULL);
	factor_product = nmemb * size;
	alloc = malloc(factor_product);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, factor_product);
	return (alloc);
}
