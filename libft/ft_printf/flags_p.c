/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_p.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:39:23 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:39:25 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	bigger_precision(unsigned long addr, int len, t_flagstruct flags)
{
	int	spaces;
	int	padding;

	spaces = flags.width - flags.precision;
	padding = flags.precision - len;
	if ((flags.width > flags.precision) && !flags.left_aligned)
	{
		print_space(spaces);
		ft_putptr(addr, padding);
	}
	else if (flags.width > flags.precision)
	{
		ft_putptr(addr, padding);
		print_space(spaces);
	}
	else
		ft_putptr(addr, padding);
}

static void	bigger_width(unsigned long addr, int len, t_flagstruct flags)
{
	int	filler;

	filler = flags.width - len;
	if (flags.left_aligned)
	{
		ft_putptr(addr, 0);
		print_space(filler);
	}
	else if (flags.zeroes && flags.precision < 0)
		ft_putptr(addr, filler);
	else
	{
		print_space(filler);
		ft_putptr(addr, 0);
	}
}

void	flags_p(void *input, t_flagstruct flags)
{
	int				len;
	unsigned long	addr;

	flags.width = flags.width - 2;
	addr = (unsigned long)input;
	len = hexa_len(addr);
	if (!addr && !flags.precision)
	{
		if (flags.left_aligned)
			ft_putnstr("0x", 2);
		print_space(flags.width);
		if (!flags.left_aligned)
			ft_putnstr("0x", 2);
		return ;
	}
	if (len >= (flags.width) && len >= flags.precision)
		ft_putptr(addr, 0);
	if (flags.precision > len)
		return (bigger_precision(addr, len, flags));
	if (flags.width > len)
		bigger_width(addr, len, flags);
}
