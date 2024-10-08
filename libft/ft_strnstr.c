/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:28:44 by varodrig          #+#    #+#             */
/*   Updated: 2024/06/06 16:38:40 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	littlelen;

	if (!*little)
		return ((char *)big);
	littlelen = ft_strlen(little);
	if (littlelen == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (*big && len >= littlelen)
	{
		if (*big == *little && ft_memcmp(big, little, littlelen) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
