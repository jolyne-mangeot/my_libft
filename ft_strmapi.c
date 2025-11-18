/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:12:23 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/14 18:05:07 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*iterate_string;
	size_t	string_len;

	if (!s || !f)
		return (NULL);
	string_len = ft_strlen(s);
	iterate_string = (char *)malloc((string_len + 1) * sizeof(char));
	if (!iterate_string)
		return (NULL);
	iterate_string[string_len] = 0;
	while (string_len--)
		iterate_string[string_len] = f(string_len, s[string_len]);
	return (iterate_string);
}
