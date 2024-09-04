/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:45:52 by juanhern          #+#    #+#             */
/*   Updated: 2024/03/19 11:34:33 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dst;

	ptr_src = (const unsigned char *)src;
	ptr_dst = (unsigned char *)dst;
	if (!ptr_dst && !ptr_src)
		return (NULL);
	while (n--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
