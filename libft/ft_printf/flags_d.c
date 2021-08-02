/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_d.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:38:47 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:38:50 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	negative_input(int input, int precision)
{
	if (input < 0 && precision != -1)
		precision = precision + 1;
	return (precision);
}

static void	bigger_precision(int input, int len, t_flagstruct flags)
{
	int	padding;
	int	spaces;

	spaces = flags.width - flags.precision;
	padding = flags.precision - len;
	if ((flags.width > flags.precision) && !flags.left_aligned)
	{
		print_space(spaces);
		input = print_padding(padding, input);
		ft_putnbr(input);
	}
	else if (flags.width > flags.precision)
	{
		input = print_padding(padding, input);
		ft_putnbr(input);
		print_space(spaces);
	}
	else
	{
		input = print_padding(padding, input);
		ft_putnbr(input);
	}
}

static void	bigger_width(int input, int len, t_flagstruct flags)
{
	int	filler;

	filler = flags.width - len;
	if (flags.left_aligned)
	{
		ft_putnbr(input);
		print_space(filler);
	}
	else if (flags.zeroes && flags.precision < 0)
	{
		input = print_padding(filler, input);
		ft_putnbr(input);
	}
	else
	{
		print_space(filler);
		ft_putnbr(input);
	}
}

void	flags_d(int input, t_flagstruct flags)
{
	int	len;

	len = int_len(input);
	flags.precision = (negative_input(input, flags.precision));
	if (!input && !flags.precision)
		return (print_space(flags.width));
	if (len >= flags.width && len >= flags.precision)
		ft_putnbr(input);
	if (flags.precision > len)
		return (bigger_precision(input, len, flags));
	if (flags.width > len)
		bigger_width(input, len, flags);
}
