/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:37:42 by jmangeot          #+#    #+#             */
/*   Updated: 2025/11/14 18:06:58 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*new_string;
	size_t	index;

	if (!src)
		return (NULL);
	index = 0;
	while (src[index])
		index++;
	new_string = (char *)malloc((index + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, src, index + 1);
	return (new_string);
}
