/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 15:39:25 by lwray         #+#    #+#                 */
/*   Updated: 2020/12/11 17:29:22 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const char		*begin_src;
	unsigned int	count;
	int				count_src;

	if (!src)
		return (0);
	begin_src = src;
	count_src = 0;
	while (*begin_src != '\0')
	{
		begin_src++;
		count_src++;
	}
	if (size == 0)
		return (count_src);
	count = 0;
	while (count < (size - 1) && (*src != '\0'))
	{
		*dest = *src;
		dest++;
		src++;
		count++;
	}
	*dest = '\0';
	return (count_src);
}
