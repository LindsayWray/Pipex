/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_u.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:39:41 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:39:43 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_length_uns(unsigned int n)
{
	int	len;

	len = 0;
	while ((n / 10) > 0)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static void	bigger_precision(unsigned int input, int len, t_flagstruct flags)
{
	int	spaces;
	int	padding;

	spaces = flags.width - flags.precision;
	padding = flags.precision - len;
	if ((flags.width > flags.precision) && !flags.left_aligned)
	{
		print_space(spaces);
		input = print_padding(padding, input);
		ft_putnbr_uns(input);
	}
	else if (flags.width > flags.precision)
	{
		input = print_padding(padding, input);
		ft_putnbr_uns(input);
		print_space(spaces);
	}
	else
	{
		input = print_padding(padding, input);
		ft_putnbr_uns(input);
	}
}

static void	bigger_width(unsigned int input, int len, t_flagstruct flags)
{
	int	filler;

	filler = flags.width - len;
	if (flags.left_aligned)
	{
		ft_putnbr_uns(input);
		print_space(filler);
	}
	else if (flags.zeroes && flags.precision < 0)
	{
		input = print_padding(filler, input);
		ft_putnbr_uns(input);
	}
	else
	{
		print_space(filler);
		ft_putnbr_uns(input);
	}
}

void	flags_u(unsigned int input, t_flagstruct flags)
{
	int	len;

	len = int_length_uns(input);
	if (!input && !flags.precision)
		return (print_space(flags.width));
	if (len >= flags.width && len >= flags.precision)
		ft_putnbr_uns(input);
	if (flags.precision > len)
		return (bigger_precision(input, len, flags));
	if (flags.width > len)
		bigger_width(input, len, flags);
}
