/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 19:04:57 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/17 21:27:47 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup((char *)s1));
	while (s1[i] != '\0')
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	if (s1[i] == '\0')
		return (ft_strdup(""));
	len = ft_strlen((char *)s1);
	while (len > 0)
	{
		if (!ft_strchr(set, s1[len - 1]))
			break ;
		len--;
	}
	return (ft_substr(s1, i, len - i));
}
