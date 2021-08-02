/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_path.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 21:22:18 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/02 21:22:28 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free (array);
}

static char	**find_env_paths(char **envp)
{
	while (envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (ft_splits(*envp, "=:"));
		envp++;
	}
	return (NULL);
}

char	*get_path(char *command, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	if (access(command, X_OK) == 0)
		return (ft_strdup(command));
	paths = find_env_paths(envp);
	command = ft_strjoin("/", command);
	i = 1;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], command);
		if (access(path, X_OK) == 0)
		{
			free (command);
			free_array(paths);
			return (path);
		}
		free (path);
		i++;
	}
	command_not_found_error(command + 1);
	free (command);
	free_array(paths);
	exit (EXIT_FAILURE);
}
