/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putdecimal_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:39:11 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:39:13 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putdecimal(long double decimal, int dec_len)
{
	int	i;
	int	nb;

	i = 0;
	if (decimal < 0)
		decimal = decimal * -1;
	nb = decimal;
	decimal = decimal - nb;
	while (i < dec_len)
	{
		decimal = decimal * 10;
		nb = decimal;
		ft_putchar(nb + '0');
		decimal = decimal - nb;
		i++;
	}
}

static double	round_up(double input, int dec_len)
{
	double	to_add;

	to_add = 0.55;
	while (dec_len > 0)
	{
		to_add = to_add / 10;
		dec_len--;
	}
	if (input < 0)
		input = input - to_add;
	else
		input = input + to_add;
	return (input);
}

double	decimal_rounding(double input, int dec_len)
{
	int			i;
	long long	nb;
	long double	copy;

	i = 0;
	copy = input;
	while (i < dec_len)
	{
		copy = copy * 10;
		i++;
	}
	nb = copy;
	if ((copy - nb) >= 0.5 || (copy - nb) <= -0.5)
	{
		if (((copy - nb == 0.5) || (copy - nb == -0.5)) && (nb % 2 == 0))
			return (input);
		input = round_up(input, dec_len);
	}
	return (input);
}
