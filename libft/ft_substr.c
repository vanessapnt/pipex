/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:36:22 by varodrig          #+#    #+#             */
/*   Updated: 2024/05/28 12:44:34 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start < len_s)
	{
		if (len_s - start < len)
			len = len_s - start;
		cpy = (char *)malloc((len + 1) * sizeof(char));
		if (!cpy)
			return (NULL);
		ft_strlcpy(cpy, s + start, len + 1);
	}
	else
		return (ft_strdup(""));
	return (cpy);
}
