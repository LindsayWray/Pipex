/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 09:41:00 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:40:28 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return ;
	char_count(1);
}
