/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:50:40 by varodrig          #+#    #+#             */
/*   Updated: 2024/05/23 14:07:27 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*flag;

	flag = NULL;
	while (*s)
	{
		if (*s == (char)c)
			flag = s;
		s++;
	}
	if (*s == (char)c)
			flag = s;
	return ((char *)flag);
}
