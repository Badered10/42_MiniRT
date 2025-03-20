/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abchikhi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:15:22 by abchikhi          #+#    #+#             */
/*   Updated: 2023/11/08 22:59:58 by abchikhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char *separators)
{
	int				i;
	unsigned int	in_word;

	i = 0;
	in_word = 0;
	while (*str)
	{
		if (!ft_strchr(separators, *str) && in_word == 0)
		{
			in_word = 1;
			i++;
		}
		else if (ft_strchr(separators, *str))
			in_word = 0;
		str++;
	}
	return (i);
}

static int	free_everything(char **array, int index)
{
	while (index > 0)
		delete_(array[--index]);
	delete_(array);
	return (0);
}

static char	*extract_word(char const *s, char *separators)
{
	int			len;
	char const	*starting;
	char		*word;
	int			i;

	len = 0;
	starting = s;
	i = 0;
	while (*s && !ft_strchr(separators, *s))
	{
		len++;
		s++;
	}
	word = (char *)new_((len + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = starting[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static int	fill_and_test(char const *s, char *separators, char **result)
{
	int		i;
	char	*word;

	i = 0;
	while (*s)
	{
		if (*s && !ft_strchr(separators, *s))
		{
			word = extract_word(s, separators);
			if (word == NULL)
				return (free_everything(result, i));
			result[i++] = word;
			while (*s && !ft_strchr(separators, *s))
				s++;
		}
		else
			s++;
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char *separators)
{
	int		word_count;
	char	**result;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, separators);
	result = (char **)new_((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (fill_and_test(s, separators, result) == 0)
		return (NULL);
	return (result);
}
