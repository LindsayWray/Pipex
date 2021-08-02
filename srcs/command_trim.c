/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   command_trim.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 21:21:44 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/02 21:21:56 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*trim_quotes(char *s1)
{
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1);
	if ((s1[0] == '\'' && s1[len - 1] == '\'')
		|| (s1[0] == '"' && s1[len - 1] == '"'))
		return (ft_substr(s1, 1, len - 2));
	else
		return (ft_strdup(s1));
}
