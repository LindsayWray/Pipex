/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_splits.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lwray <lwray@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 15:56:18 by lwray         #+#    #+#                 */
/*   Updated: 2020/12/11 17:27:46 by lwray         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char *charset)
{
	while (*charset != '\0')
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_in_set(str[i], charset) == 0)
			if (str[i + 1] == '\0' || char_in_set(str[i + 1], charset) == 1)
				count++;
		i++;
	}
	return (count);
}

char	*next_word(char *str, int i, char *charset)
{
	int		len;
	char	*new_word;
	int		k;
	int		start;

	len = 0;
	start = i;
	while (char_in_set(str[i], charset) == 0 && str[i] != '\0')
	{
		len++;
		i++;
	}
	new_word = (char *)malloc((len + 1) * sizeof(char));
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

char	**ft_splits(char *str, char *charset)
{
	char	**strs;
	int		word_count;
	int		i;
	int		j;

	word_count = count_words(str, charset);
	strs = (char **)malloc((word_count + 1) * sizeof(char *));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (char_in_set(str[i], charset) == 0)
		{
			if (i == 0 || char_in_set(str[i - 1], charset) == 1)
			{
				strs[j] = next_word(str, i, charset);
				j++;
			}
		}
		i++;
	}
	strs[word_count] = NULL;
	return (strs);
}
