/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:14:10 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/14 18:05:36 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cast_c;
	size_t	string_len;

	cast_c = (char)c;
	string_len = ft_strlen(s);
	if (!c)
		return ((char *)s + string_len);
	while (string_len--)
		if (s[string_len] == cast_c)
			return ((char *)s + string_len);
	return (NULL);
}
