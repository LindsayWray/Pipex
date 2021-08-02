/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/24 12:30:45 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:40:17 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	t_flagstruct	flags;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flags = flagcheck((char *)format, ap);
			while (!is_specifier(*format) && *format)
				format++;
			ft_conversion(ap, *format, flags);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end (ap);
	return (char_count(0));
}
