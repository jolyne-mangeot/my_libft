/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:29:19 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:17:24 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**fill_array(char **split_s, char *cast_s, char c)
{
	size_t	count_w;
	size_t	string_len;

	count_w = 0;
	while (*cast_s)
	{
		while (*cast_s == c)
			cast_s++;
		if (*cast_s != 0)
		{
			string_len = 0;
			while (cast_s[string_len] != c && cast_s[string_len] != 0)
				string_len++;
			split_s[count_w] = ft_substr(cast_s, 0, string_len);
			if (!split_s[count_w++])
			{
				while (count_w--)
					free(split_s[count_w]);
				free(split_s);
				return (NULL);
			}
			cast_s += string_len;
		}
	}
	return (split_s);
}

char	**ft_split(const char *s, char c)
{
	char	**split_s;
	char	*cast_s;
	size_t	count_w;

	if (!s)
		return (NULL);
	cast_s = (char *)s;
	count_w = 0;
	while (*cast_s++)
		if (*(cast_s - 1) != c && (*cast_s == 0 || *cast_s == c))
			count_w++;
	split_s = (char **)malloc(sizeof(char *) * (count_w + 1));
	if (!split_s)
		return (NULL);
	split_s[count_w] = NULL;
	return (fill_array(split_s, (char *)s, c));
}
