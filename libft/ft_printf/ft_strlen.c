/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:41:54 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:41:56 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strlen_or_precision(char *str, int precision)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (len > precision && precision >= 0)
		return (precision);
	return (len);
}
