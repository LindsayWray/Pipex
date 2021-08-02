/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_command.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/02 21:23:11 by lwray         #+#    #+#                 */
/*   Updated: 2021/08/02 21:23:12 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(char const *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i] != '\0')
				i++;
		}
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\0')
				i++;
		}
		if (str[i] != ' ')
			if (str[i + 1] == '\0' || str[i + 1] == ' ')
				count++;
		i++;
	}
	return (count);
}

int	word_len(char const *str, int i)
{
	int	start;

	start = i;
	while ((str[i] != ' ') && (str[i] != '\0'))
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\0')
				i++;
		}
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i] != '\0')
				i++;
		}
		i++;
	}
	return (i - start);
}

static char	*next_word(char const *str, int start)
{
	int		len;
	char	*new_word;
	int		k;

	len = word_len(str, start);
	new_word = (char *)malloc((len + 1) * sizeof(char));
	if (new_word == NULL)
		return (0);
	k = 0;
	while (k < len && str[start] != '\0')
	{
		new_word[k] = str[start];
		start++;
		k++;
	}
	new_word[len] = '\0';
	return (new_word);
}

int	splitting(char const *str, char **strs)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ') && (i == 0 || (str[i - 1] == ' ')))
		{
			temp = next_word(str, i);
			strs[j] = trim_quotes(temp);
			if (strs[j] == NULL)
			{
				free_array(strs);
				return (0);
			}
			i += ft_strlen(temp);
			free (temp);
			j++;
		}
		else
			i++;
	}
	return (1);
}

char	**split_command(char const *str)
{
	char	**strs;
	int		word_count;

	if (!str)
		return (NULL);
	word_count = count_words(str);
	strs = (char **)malloc((word_count + 1) * sizeof (char *));
	if (!strs)
		return (NULL);
	if (!splitting(str, strs))
		return (NULL);
	strs[word_count] = NULL;
	return (strs);
}
