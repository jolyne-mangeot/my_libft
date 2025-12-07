/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:23:47 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 13:54:50 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
return argument as uppercase if possible, otherwise argument doesn't change.
*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
