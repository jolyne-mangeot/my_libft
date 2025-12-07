/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:30:11 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:52:55 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
check if argument is an ASCII character (0 to 127) and returns a boolean value.
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
