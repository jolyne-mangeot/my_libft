/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:09:56 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:56:23 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
locate and return a pointer to the first occurence of a character in a string, 
otherwise NULL.
*/
char	*ft_strchr(const char *s, int c)
{
	char	*cast_s;
	char	cast_c;

	cast_s = (char *)s;
	if (!c)
		return (cast_s + ft_strlen(s));
	cast_c = (char)c;
	while (*cast_s)
		if (*cast_s++ == cast_c)
			return (cast_s - 1);
	return (NULL);
}
