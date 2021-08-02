/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 10:01:35 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/27 10:14:36 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long addr, int padding)
{
	ft_putnstr("0x", 2);
	print_padding(padding, addr);
	ft_putnbr_hexa(addr, "0123456789abcdef");
}
