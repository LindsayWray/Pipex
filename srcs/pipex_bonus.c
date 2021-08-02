/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 21:23:02 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/02 21:23:04 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	multiple_commands(int read_pipe, int argc, char **argv, char **envp)
{
	int		i;
	pid_t	pid;
	int		p[2];

	i = 2;
	while (i < (argc - 2))
	{
		if (pipe(p) == -1)
			error("pipe error");
		pid = fork();
		if (pid == -1)
			error("fork error");
		if (pid == 0)
			process(read_pipe, p[1], argv [i], envp);
		wait (0);
		close (p[1]);
		read_pipe = p[0];
		i++;
	}
	return (read_pipe);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		last_pipe;

	if (argc < 4)
		arg_error();
	if (ft_strequal(argv[1], "here_doc"))
		heredoc_process(argv, envp);
	last_pipe = multiple_commands(get_input(argv[1]), argc, argv, envp);
	pid = fork();
	if (pid == -1)
		error("fork error");
	if (pid == 0)
		process(last_pipe, get_output(argv[argc - 1]), argv[argc - 2], envp);
	close (last_pipe);
	wait (0);
	return (0);
}
