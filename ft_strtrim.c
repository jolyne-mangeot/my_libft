/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:50:50 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/14 18:05:59 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*cast_s1;
	char	*trim_string;
	size_t	trim_len;

	if (!s1 || !set)
		return (NULL);
	cast_s1 = (char *)s1;
	while (*cast_s1 && ft_strchr(set, *cast_s1))
		cast_s1++;
	trim_len = ft_strlen(cast_s1);
	while (*cast_s1 && ft_strchr(set, cast_s1[trim_len - 1]))
		trim_len--;
	trim_string = (char *)malloc(trim_len + 1 * sizeof(char));
	if (!trim_string)
		return (NULL);
	ft_strlcpy(trim_string, cast_s1, trim_len + 1);
	return (trim_string);
}
