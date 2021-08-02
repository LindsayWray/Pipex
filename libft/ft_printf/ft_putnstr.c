/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 09:43:24 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:41:46 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && i != n)
	{
		ft_putchar(str[i]);
		i++;
	}
}
