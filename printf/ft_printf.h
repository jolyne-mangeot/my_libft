/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmangeot <jmangeot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 20:46:47 by jmangeot          #+#    #+#             */
/*   Updated: 2025/12/07 17:50:11 by jmangeot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

//*			Module callable function
int		ft_printf(const char *format, ...);

//*			Variables printing
int		ft_put_char(char c);
int		ft_put_str(char *s);
int		ft_put_ptr(unsigned long int ptr);
int		ft_put_signed(signed int number,
			signed int base, char *digits);
int		ft_put_unsigned(unsigned int number,
			unsigned int base, char *digits);
int		ft_put_lsigned(signed long int number,
			signed long int base, char *digits);
int		ft_put_lunsigned(unsigned long int number,
			unsigned long int base, char *digits);
int		ft_put_llsigned(signed long long int number,
			signed long long int base, char *digits);
int		ft_put_llunsigned(unsigned long long int number,
			unsigned long long int base, char *digits);

#endif
