/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 09:44:33 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:40:42 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnstr("-2147483648", 12);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb / 10 != 0)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr_uns(unsigned int nb)
{
	if (nb / 10 != 0)
		ft_putnbr_uns(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr_hexa(unsigned long input, char *base)
{
	int	remainder;

	if (input / 16 > 0)
		ft_putnbr_hexa((input / 16), base);
	remainder = input % 16;
	ft_putchar(base[remainder]);
}
