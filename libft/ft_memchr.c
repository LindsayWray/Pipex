/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 16:01:28 by lwray         #+#    #+#                 */
/*   Updated: 2020/12/11 19:44:46 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptrs;

	ptrs = s;
	while (n > 0)
	{
		if (*ptrs == (char)c)
			return ((void *)ptrs);
		ptrs++;
		n--;
	}
	return (0);
}
