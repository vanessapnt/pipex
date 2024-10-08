/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:45:28 by varodrig          #+#    #+#             */
/*   Updated: 2024/05/28 12:55:31 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	spaceleft;
	size_t	i;
	size_t	o;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	spaceleft = size - dstlen - 1;
	if (dstlen >= size)
		return (size + srclen);
	i = 0;
	while (dst[i])
		i++;
	o = 0;
	while (src[o] && spaceleft > 0)
	{
		dst[i] = src[o];
		i++;
		o++;
		spaceleft--;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
