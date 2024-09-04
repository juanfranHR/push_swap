/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:15:48 by juanhern          #+#    #+#             */
/*   Updated: 2024/04/12 11:42:38 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	num_words;
	size_t	i;

	i = 0;
	if (!s && s[i] == '\0')
		return (0);
	num_words = 0;
	if (s[i] != c && s[i] != '\0')
		num_words++;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && i != 0 && s[i - 1] == c)
			num_words++;
		i++;
	}
	return (num_words);
}

static char	**dest_allocation(char const *s, char c)
{
	char	**dest;

	dest = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}

static char	*ft_word_allocation(char const *s, char c)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!dest)
		dest = NULL;
	else
	{
		while (s[i] && s[i] != c)
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

static char	**free_mem(char **dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	dest = NULL;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	dest = dest_allocation(s, c);
	while (*s && dest != NULL)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			dest[i] = ft_word_allocation(s, c);
			if (!dest[i])
				dest = free_mem(dest);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	if (dest != NULL)
		dest[i] = NULL;
	return (dest);
}
