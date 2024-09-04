/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:46:03 by juanhern          #+#    #+#             */
/*   Updated: 2024/04/11 20:31:53 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <stdio.h>

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] && j + i < size - 1 && size > 0)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (size > 0 && size >= i)
		dest[i + j] = '\0';
	if (size <= i)
		return (ft_strlen(src) + size);
	else
		return (i + ft_strlen(src));
}
