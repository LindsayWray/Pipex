/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 21:22:52 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/02 21:22:54 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

void	process(int input_fd, int output_fd, char *full_command, char **envp);
int		get_output(char *output_file);
int		get_input(char *input_file);
char	**split_command(char const *str);
char	*trim_quotes(char *s1);
char	*get_path(char *command, char **envp);
void	free_array(char **array);
void	command_not_found_error(char *command);
void	error(char *error_message);
void	arg_error(void);
void	heredoc_process(char **argv, char **envp);

#endif
