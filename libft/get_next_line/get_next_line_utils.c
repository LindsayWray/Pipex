/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 17:39:14 by lwray         #+#    #+#                 */
/*   Updated: 2021/03/02 17:39:19 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	go_back(char *buff, char *rest)
{
	int	i;

	i = 0;
	while (*buff != '\0' && *buff != '\n')
		buff++;
	if (*buff == '\n')
	{
		buff++;
		while (buff[i] != '\0')
		{
			rest[i] = buff[i];
			i++;
		}
		rest[i] = '\0';
	}
}

char	*concat(char *temp_line, char *addstr)
{
	int		i;
	int		j;
	char	*cc_str;

	i = 0;
	cc_str = malloc(ft_strlen(temp_line) + ft_strlen(addstr) + 1);
	if (!cc_str)
		return (NULL);
	while (temp_line[i] != '\0')
	{
		cc_str[i] = temp_line[i];
		i++;
	}
	j = 0;
	while (addstr[j] != '\0' && addstr[j] != '\n')
	{
		cc_str[i + j] = addstr[j];
		j++;
	}
	cc_str[i + j] = '\0';
	free(temp_line);
	return (cc_str);
}

int	find_newline(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*split_rest(char *rest)
{
	char	*ret_str;
	int		i;

	i = 0;
	while (rest[i] != '\n')
		i++;
	ret_str = malloc(i + 1);
	if (!ret_str)
		return (NULL);
	i = 0;
	while (rest[i] != '\n')
	{
		ret_str[i] = rest[i];
		i++;
	}
	ret_str[i] = '\0';
	go_back(rest, rest);
	return (ret_str);
}
