/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_f_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:39:11 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:39:13 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_negative(double input)
{
	if (*((unsigned long *)(&input)) & 0x8000000000000000)
		return (1);
	else
		return (0);
}

static void	putfloat(double input, int dec_len)
{
	if (is_negative(input) && input > -1)
		ft_putchar('-');
	ft_putnbr(input);
	if (dec_len)
		ft_putchar('.');
	ft_putdecimal(input, dec_len);
}

static void	bigger_width(double input, int len, int dec_len, t_flagstruct flags)
{
	int	filler;

	filler = flags.width - len;
	if (is_negative(input) && input > -1)
		filler--;
	if (flags.left_aligned)
	{
		putfloat(input, dec_len);
		print_space(filler);
	}
	else if (flags.zeroes)
	{
		if (is_negative(input))
		{
			ft_putchar('-');
			input = input * -1;
		}
		print_padding(filler, input);
		putfloat(input, dec_len);
	}
	else
	{
		print_space(filler);
		putfloat(input, dec_len);
	}
}

void	flags_f(double input, t_flagstruct flags)
{
	int	len;
	int	dec_len;

	dec_len = 6;
	if (flags.precision >= 0)
		dec_len = flags.precision;
	input = decimal_rounding(input, dec_len);
	len = int_len(input) + dec_len;
	if (dec_len)
		len ++;
	if (len >= flags.width)
		putfloat(input, dec_len);
	if (flags.width > len)
		bigger_width(input, len, dec_len, flags);
}
