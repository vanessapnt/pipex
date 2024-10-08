/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:01:00 by varodrig          #+#    #+#             */
/*   Updated: 2024/05/28 11:04:03 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		needle;

	str = (const unsigned char *)s;
	needle = (unsigned char)c;
	while (n > 0)
	{
		if (*str == needle)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
