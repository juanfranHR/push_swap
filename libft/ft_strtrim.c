/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:17:07 by juanhern          #+#    #+#             */
/*   Updated: 2024/05/25 11:46:53 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_start(char const *s1, char const *set)
{
	size_t	index;
	int		found;
	int		index_set;

	if (ft_strlen(s1) == 0)
		return (0);
	found = 1;
	index = 0;
	index_set = 0;
	while (s1[index] && found == 1)
	{
		found = 0;
		while (set[index_set])
		{
			if (set[index_set] == s1[index])
				found = 1;
			index_set++;
		}
		index_set = 0;
		if (found == 0)
			break ;
		index++;
	}
	return (index);
}

static size_t	ft_get_end(char const *s1, char const *set)
{
	size_t	index;
	int		found;
	int		index_set;

	if (ft_strlen(set) == 0 || ft_strlen(s1) == 0)
		return (ft_strlen(s1));
	found = 1;
	index = ft_strlen(s1) - 1;
	index_set = 0;
	while (s1[index] && found == 1)
	{
		found = 0;
		while (set[index_set])
		{
			if (set[index_set] == s1[index])
				found = 1;
			index_set++;
		}
		index_set = 0;
		if (found == 0 || index == 0)
			break ;
		index--;
	}
	return (index);
}

static char	*ft_mem_alloc(char const *s1, size_t start, size_t end)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (ft_strlen(s1) == 0 || start > end)
	{
		dst = malloc(sizeof(char) * 1);
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	else
	{
		dst = malloc(sizeof(char) * (end - start + 2));
		if (!dst)
			return (NULL);
		while (start + i <= end)
		{
			dst[i] = s1[start + i];
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	if (ft_strlen(set) == 0)
		return (ft_mem_alloc(s1, 0, ft_strlen(s1) - 1));
	else
		return (ft_mem_alloc(s1, start, end));
}
