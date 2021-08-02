/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conversion.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 09:47:36 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:40:06 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion(va_list ap, char conv, t_flagstruct flags)
{
	if (conv == 'c')
		flags_c((va_arg(ap, int)), flags);
	else if (conv == 's')
		flags_s(va_arg(ap, char *), flags);
	else if (conv == 'p')
		flags_p(va_arg(ap, void *), flags);
	else if (conv == 'd' || conv == 'i')
		flags_d(va_arg(ap, int), flags);
	else if (conv == 'u')
		flags_u(va_arg(ap, unsigned int), flags);
	else if (conv == 'x')
		flags_x(va_arg(ap, unsigned int), "0123456789abcdef", flags);
	else if (conv == 'X')
		flags_x(va_arg(ap, unsigned int), "0123456789ABCDEF", flags);
	else if (conv == '%')
		flags_c('%', flags);
	else if (conv == 'f')
		flags_f(va_arg(ap, double), flags);
}
