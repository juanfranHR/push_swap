/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:48:59 by juanhern          #+#    #+#             */
/*   Updated: 2024/04/11 20:30:44 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_compare(const char *haystack, const char *needle, size_t i,
		size_t len)
{
	while (*haystack && *needle && i < len)
	{
		if (*haystack != *needle)
			return (0);
		haystack++;
		needle++;
		i++;
	}
	return (*needle == '\0');
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack && i < len)
	{
		if ((*haystack == *needle) && ft_compare(haystack, needle, i, len))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
