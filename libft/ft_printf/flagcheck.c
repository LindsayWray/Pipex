/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flagcheck.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/27 13:30:07 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/28 16:56:20 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_left_aligned(char *str)
{
	while (*str == '0' || *str == '-')
	{
		if (*str == '-')
			return (1);
		str++;
	}
	return (0);
}

int	is_zeroes(char *str)
{
	if (*str == '0')
		return (1);
	return (0);
}

int	get_int(char *str, va_list wildcard)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] == '0' || str[i] == '-')
		i++;
	if (str[i] == '*')
		return (va_arg(wildcard, int));
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	get_precision(char *str, va_list wildcard)
{
	while (!is_specifier(*str) && *str)
	{
		if (*str == '.')
		{
			str++;
			return (get_int(str, wildcard));
		}
		str++;
	}
	return (-1);
}

t_flagstruct	flagcheck(char *str, va_list wildcard)
{
	t_flagstruct	flags;

	flags.left_aligned = is_left_aligned(str);
	if (!flags.left_aligned)
		flags.zeroes = is_zeroes(str);
	flags.width = get_int(str, wildcard);
	if (flags.width < 0)
	{
		flags.width *= -1;
		flags.left_aligned = 1;
	}
	flags.precision = get_precision(str, wildcard);
	return (flags);
}
