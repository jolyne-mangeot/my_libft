/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:14:10 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:56:35 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
locate and return a pointer to the last occurence of a character in a string, 
otherwise NULL.
*/
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
