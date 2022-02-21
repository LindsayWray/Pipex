/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 21:22:38 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/02 21:22:42 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		p[2];

	if (argc != 5)
		arg_error();
	if (pipe(p) == -1)
		error("pipe error");
	pid = fork();
	if (pid == -1)
		error("fork error");
	if (pid == 0)
		process(get_input(argv[1]), p[1], argv [2], envp);
	pid = fork();
	if (pid == -1)
		error("fork error");
	if (pid == 0)
	{
		close (p[1]);
		process(p[0], get_output(argv[4]), argv[3], envp);
	}
	wait (0);
	close (p[1]);
	close (p[0]);
	wait (0);
	return (0);
}
