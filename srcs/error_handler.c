/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 21:23:18 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/02 21:23:22 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *error_message)
{
	perror (error_message);
	exit (EXIT_FAILURE);
}

void	command_not_found_error(char *command)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
}

void	arg_error(void)
{
	ft_putstr_fd("Error: incorrect amount of arguments\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}
