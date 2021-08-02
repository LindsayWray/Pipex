/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 21:23:26 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/02 21:23:28 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	read_input(int fd_pipe, char *delimiter)
{
	char	*line;

	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (ft_strequal(line, delimiter))
		{
			free (line);
			close (fd_pipe);
			return ;
		}
		ft_putstr_fd (line, fd_pipe);
		ft_putchar_fd ('\n', fd_pipe);
		free (line);
	}
}

static int	get_output_append(char *output_file)
{
	int		output_fd;

	output_fd = open(output_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (output_fd == -1)
		error("couldn't open output_file");
	return (output_fd);
}

static void	heredoc_child_process(int write_fd, char **argv, char **envp)
{
	int		input_pipe[2];

	if (pipe (input_pipe) == -1)
		error("pipe error");
	read_input(input_pipe[1], argv[2]);
	close (input_pipe[1]);
	process(input_pipe[0], write_fd, argv[3], envp);
}

void	heredoc_process(char **argv, char **envp)
{
	pid_t	pid;
	int		p[2];

	if (pipe(p) == -1)
		error("pipe error");
	pid = fork();
	if (pid == -1)
		error("fork error");
	if (pid == 0)
		heredoc_child_process(p[1], argv, envp);
	wait (0);
	close (p[1]);
	pid = fork();
	if (pid == -1)
		error("fork error");
	if (pid == 0)
		process(p[0], get_output_append(argv[5]), argv[4], envp);
	close (p[0]);
	wait (0);
	exit (EXIT_SUCCESS);
}
