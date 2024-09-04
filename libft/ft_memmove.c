/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:44:22 by juanhern          #+#    #+#             */
/*   Updated: 2024/03/19 11:34:34 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*ptr_src;
	char unsigned		*ptr_dst;

	ptr_src = (const unsigned char *)src;
	ptr_dst = (unsigned char *)dst;
	if (!ptr_dst && !ptr_src)
		return (NULL);
	if (ptr_src > ptr_dst)
		while (len--)
			*ptr_dst++ = *ptr_src++;
	else
	{
		ptr_dst = (ptr_dst + len - 1);
		ptr_src = (ptr_src + len - 1);
		while (len--)
			*ptr_dst-- = *ptr_src--;
	}
	return (dst);
}
