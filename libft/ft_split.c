/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:47:04 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/10 19:10:51 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count_strings(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			if (*s != '\n')
				count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_all(char **result, int ctr)
{
	while (ctr > 0)
	{
		ctr--;
		free(result[ctr]);
	}
	free(result);
}

static char	*malloc_string(char const *s, char c)
{
	char	*word;
	int		len;
	int		ctr;

	len = 0;
	ctr = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (ctr < len)
	{
		word[ctr] = s[ctr];
		ctr++;
	}
	word[len] = '\0';
	return (word);
}

static int	split_words(char **result, char const *s, char c, int words)
{
	int	ctr;

	ctr = 0;
	while (*s && ctr < words)
	{
		if (*s != c)
		{
			result[ctr] = malloc_string(s, c);
			if (!result[ctr])
				return (ctr);
			ctr++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[ctr] = NULL;
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		error_idx;

	if (!s)
		return (NULL);
	words = count_strings(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	error_idx = split_words(result, s, c, words);
	if (error_idx != -1)
	{
		free_all(result, error_idx);
		return (NULL);
	}
	return (result);
}
