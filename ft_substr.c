/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:13:35 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 14:00:05 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
return a string of characters copied from a source from an index start and on a 
maximum input length.
*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	sublen;

	if (!s)
		return (NULL);
	sublen = ft_strlen(s);
	if (sublen < start)
		return ((char *)ft_calloc(1, 1));
	sublen -= start;
	if (sublen > len)
		sublen = len;
	substr = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, sublen + 1);
	return (substr);
}
