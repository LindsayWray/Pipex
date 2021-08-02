/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/02 17:38:58 by lwray         #+#    #+#                 */
/*   Updated: 2021/03/02 17:39:01 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
void	go_back(char *buff, char *rest);
int		ft_strlen(char *str);
char	*concat(char *first_line, char *addstr);
int		find_newline(char *buff);
char	*split_rest(char *rest);
char	*ft_strdup(char *src);

#endif
