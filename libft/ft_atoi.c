/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varodrig <varodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:05:00 by varodrig          #+#    #+#             */
/*   Updated: 2024/05/28 12:46:19 by varodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_space(int c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

static int	check_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int	result;
	int			signe;

	signe = 1;
	while (*nptr && check_space(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			signe *= -1;
		nptr++;
	}
	result = 0;
	while (*nptr && check_digit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	result = result * signe;
	return (result);
}
