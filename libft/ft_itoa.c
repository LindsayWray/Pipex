/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 16:04:51 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/17 19:40:15 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while ((n / 10) > 0)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		num_len;
	int		index;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num_len = number_len(n);
	str = (char *)malloc(num_len + 1);
	if (!str)
		return (NULL);
	str[num_len] = '\0';
	index = num_len - 1;
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	while ((n / 10) > 0)
	{
		str[index] = ((n % 10) + '0');
		n = n / 10;
		index--;
	}
	str[index] = ((n % 10) + '0');
	return (str);
}
