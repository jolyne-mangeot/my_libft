/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:46:47 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/08 15:10:31 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

//*			Module callable function

ssize_t	ft_printf(const char *format, ...);

//*			Variables printing

ssize_t	ft_put_char(char c);
ssize_t	ft_put_str(char *s);
ssize_t	ft_put_ptr(unsigned long int ptr);
ssize_t	ft_put_signed(signed int number,
			signed int base_size, char *digits);
ssize_t	ft_put_unsigned(unsigned int number,
			unsigned int base_size, char *digits);
ssize_t	ft_put_lsigned(signed long int number,
			signed long int base_size, char *digits);
ssize_t	ft_put_lunsigned(unsigned long int number,
			unsigned long int base_size, char *digits);
ssize_t	ft_put_llsigned(signed long long int number,
			signed long long int base_size, char *digits);
ssize_t	ft_put_llunsigned(unsigned long long int number,
			unsigned long long int base_size, char *digits);

#endif
