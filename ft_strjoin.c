/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:37:30 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:18:03 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined_string;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!joined_string)
		return (NULL);
	ft_strlcpy(joined_string, s1, s1_len + 1);
	ft_strlcpy(joined_string + s1_len, s2, s2_len + 1);
	return (joined_string);
}
