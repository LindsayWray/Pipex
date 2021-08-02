/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 15:00:43 by lwray         #+#    #+#                 */
/*   Updated: 2020/12/18 11:20:53 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			((char *)dst)[i] = ((unsigned char *)src)[i];
			return (dst + (i + 1));
		}
		((char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (0);
}
