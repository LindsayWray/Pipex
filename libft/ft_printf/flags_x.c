/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_x.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:39:51 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:39:53 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	bigger_precis(long input, int len, char *base, t_flagstruct flags)
{
	int	spaces;
	int	padding;

	spaces = flags.width - flags.precision;
	padding = flags.precision - len;
	if ((flags.width > flags.precision) && !flags.left_aligned)
	{
		print_space(spaces);
		print_padding(padding, input);
		ft_putnbr_hexa(input, base);
	}
	else if (flags.width > flags.precision)
	{
		input = print_padding(padding, input);
		ft_putnbr_hexa(input, base);
		print_space(spaces);
	}
	else
	{
		input = print_padding(padding, input);
		ft_putnbr_hexa(input, base);
	}
}

static void	bigger_width(long input, int len, char *base, t_flagstruct flags)
{
	int	filler;

	filler = flags.width - len;
	if (flags.left_aligned)
	{
		ft_putnbr_hexa(input, base);
		print_space(filler);
	}
	else if (flags.zeroes && flags.precision < 0)
	{
		input = print_padding(filler, input);
		ft_putnbr_hexa(input, base);
	}
	else
	{
		print_space(filler);
		ft_putnbr_hexa(input, base);
	}
}

void	flags_x(unsigned int input, char *base, t_flagstruct flags)
{
	int	len;

	len = hexa_len(input);
	if (!input && !flags.precision)
		return (print_space(flags.width));
	if (len >= flags.width && len >= flags.precision)
		ft_putnbr_hexa(input, base);
	if (flags.precision > len)
		return (bigger_precis(input, len, base, flags));
	if (flags.width > len)
		bigger_width(input, len, base, flags);
}
