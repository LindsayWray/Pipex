/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 21:23:35 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/02 21:23:37 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_output(char *output_file)
{
	int		output_fd;

	output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		error("couldn't open output_file");
	return (output_fd);
}

int	get_input(char *input_file)
{
	int		input_fd;

	input_fd = open(input_file, O_RDONLY);
	if (input_fd == -1)
		error("input file does not exist");
	return (input_fd);
}

void	process(int input_fd, int output_fd, char *full_command, char **envp)
{
	char	**command;
	char	*path;

	if (dup2(output_fd, STDOUT_FILENO) == -1)
		error("dup error");
	close (output_fd);
	if (dup2(input_fd, STDIN_FILENO) == -1)
		error("dup error");
	close (input_fd);
	command = split_command(full_command);
	path = get_path(*command, envp);
	if (execve(path, command, envp) == -1)
	{
		free_array(command);
		free (path);
		exit (EXIT_FAILURE);
	}
}
