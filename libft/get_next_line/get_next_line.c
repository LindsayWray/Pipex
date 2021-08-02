/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 18:42:50 by lwray         #+#    #+#                 */
/*   Updated: 2021/01/17 16:41:02 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	rest_line(char **line, char *rest)
{
	*line = split_rest(rest);
	if (!*line)
		return (-1);
	return (1);
}

int	continue_reading(int fd, char **line, char **temp_line, char *buff)
{
	int	chars_read;

	*temp_line = concat(*temp_line, buff);
	if (!*temp_line)
		return (0);
	chars_read = read(fd, buff, BUFFER_SIZE);
	if (chars_read < BUFFER_SIZE)
	{
		buff[chars_read] = '\0';
		if (!find_newline(buff))
		{
			*line = concat(*temp_line, buff);
			free(buff);
			return (0);
		}
	}
	return (1);
}

int	read_and_terminate(int fd, char *buff, char *temp_line)
{
	int	chars_read;

	chars_read = read(fd, buff, BUFFER_SIZE);
	if (chars_read <= 0)
	{
		free(buff);
		free(temp_line);
		return (-1);
	}
	buff[chars_read] = '\0';
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	char		*temp_line;
	static char	rest [BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if (find_newline(rest))
		return (rest_line(line, rest));
	buff = malloc(BUFFER_SIZE + 1);
	temp_line = ft_strdup(rest);
	if (!buff || !temp_line)
		return (-1);
	if (read_and_terminate(fd, buff, temp_line) == -1)
		return (-1);
	while (!find_newline(buff))
		if (!continue_reading(fd, line, &temp_line, buff))
			return (rest[0] = '\0');
	*line = concat(temp_line, buff);
	go_back(buff, rest);
	free(buff);
	return (1);
}
