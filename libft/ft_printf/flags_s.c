/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_s.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:39:30 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:39:32 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_s(char *input, t_flagstruct flags)
{
	int	len;
	int	filler;

	if (!input)
		return (flags_null(flags));
	len = strlen_or_precision(input, flags.precision);
	if (len >= flags.width)
		return (ft_putnstr(input, len));
	filler = flags.width - len;
	if (flags.left_aligned)
	{
		ft_putnstr(input, len);
		print_space(filler);
	}
	else if (flags.zeroes)
	{
		print_padding(filler, 1);
		ft_putnstr(input, len);
	}
	else
	{
		print_space(filler);
		ft_putnstr(input, len);
	}
}
