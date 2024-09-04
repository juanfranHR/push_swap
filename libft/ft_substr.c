/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:17:13 by juanhern          #+#    #+#             */
/*   Updated: 2024/04/12 09:01:54 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) - 1 && ft_strlen(s) > 0)
		len = 1;
	else if (ft_strlen(s) == 0 || len == 0)
		len = 1;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start + 1;
	else
		len += 1;
	dst = malloc(sizeof(char) * (len));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len - 1)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
