/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:34:08 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:55:00 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
return argument as lowercase if possible, otherwise argument doesn't change.
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
