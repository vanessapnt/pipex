/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:38:40 by varodrig          #+#    #+#             */
/*   Updated: 2024/05/27 17:58:34 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_digit(int n)
{
	size_t	digit_nb;

	digit_nb = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digit_nb++;
	while (n != 0)
	{
		n = n / 10;
		digit_nb++;
	}
	return (digit_nb);
}

char	*ft_itoa(int n)
{
	int		digit_nb;
	char	*dst;
	int		start;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit_nb = ft_nb_digit(n);
	dst = (char *)malloc((digit_nb + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	start = 0;
	if (n < 0)
	{
		dst[start] = '-';
		n = n * -1;
		start = 1;
	}
	dst[digit_nb] = '\0';
	while (digit_nb > start)
	{
		dst[digit_nb - 1] = (n % 10) + '0';
		n = n / 10;
		digit_nb--;
	}
	return (dst);
}
