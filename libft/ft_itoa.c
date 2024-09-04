/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:11:44 by juanhern          #+#    #+#             */
/*   Updated: 2024/04/11 19:32:04 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	while (n > 9 || n < -9)
	{
		len++;
		n /= 10;
	}
	len++;
	if (n >= 0)
		return (len);
	else
		return (len + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	i = len - 1;
	while (n > 9 || n < -9)
	{
		if (n >= 0)
			str[i--] = (n % 10) + '0';
		else
			str[i--] = -(n % 10) + '0';
		n /= 10;
	}
	if (n >= 0)
		str[i] = n + '0';
	else
		str[i] = -n + '0';
	str[len] = '\0';
	return (str);
}
