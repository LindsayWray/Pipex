/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_null.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/25 18:39:11 by lwray         #+#    #+#                 */
/*   Updated: 2021/02/25 18:39:13 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_null(t_flagstruct flags)
{
	int	len;
	int	filler;

	len = strlen_or_precision(NULLSTR, flags.precision);
	if (len >= flags.width)
		ft_putnstr(NULLSTR, len);
	else
	{
		filler = flags.width - len;
		if (flags.left_aligned)
		{
			ft_putnstr(NULLSTR, len);
			print_space(filler);
		}
		else if (flags.zeroes)
		{
			print_padding(filler, 1);
			ft_putnstr(NULLSTR, len);
		}
		else
		{
			print_space(filler);
			ft_putnstr(NULLSTR, len);
		}
	}
}
