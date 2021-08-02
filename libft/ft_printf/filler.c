/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:37:38 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:37:41 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	print_padding(int padding, long input)
{
	if (input < 0)
	{
		ft_putchar ('-');
		input = input * -1;
	}
	while (padding > 0)
	{
		ft_putchar('0');
		padding--;
	}
	return (input);
}

void	print_space(int spaces)
{
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
	}
}
