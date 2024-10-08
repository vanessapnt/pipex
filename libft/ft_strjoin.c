/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:44:18 by varodrig          #+#    #+#             */
/*   Updated: 2024/05/25 12:04:50 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dst;
	char	*dst_start;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst_start = dst;
	while (*s1)
	{
		*dst++ = *s1++;
	}
	while (*s2)
	{
		*dst++ = *s2++;
	}
	*dst = '\0';
	return (dst_start);
}
