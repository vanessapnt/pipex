/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:56:20 by varodrig          #+#    #+#             */
/*   Updated: 2024/06/05 11:23:05 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*str;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size / size != nmemb)
		return (NULL);
	len = nmemb * size;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_memset(str, 0, len);
	return (str);
}
/*
int	main(void)
{
	int	*tab;

	tab = ft_calloc(2, sizeof(int));
	free(tab);
}
*/