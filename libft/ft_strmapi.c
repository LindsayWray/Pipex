/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 18:41:10 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/17 20:20:57 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	ret_char;
	char	*ret_str;
	int		i;

	if (!s)
		return (NULL);
	ret_str = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!ret_str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ret_char = f(i, s[i]);
		ret_str[i] = ret_char;
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
